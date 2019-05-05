#pragma once
#ifndef _RAY_H_ 
#define _RAY_H_
#include <type_traits>
#include "vec3.h"

namespace CpuMode {

    template<typename T>
    class ray
    {
    public:
        ray() {}
        ray(const vec3<T>& a, const vec3<T>& b) { A = a; B = b; }
        ~ray() {}

        vec3<T> origin() const { return A; }
        vec3<T> direction() const { return B; }
        vec3<T> point_at_parameter(T t) const { return A + t * B; }

        vec3<T> A;
        vec3<T> B;
    };

    template<typename T>
    T hit_sphere(const vec3<T>& center, T radius, const ray<T>& r)
    {
        // only accept certain types
        static_assert(std::is_floating_point<T>::value, __FUNCTION__": type must be floating point\n");
        vec3<T> oc = r.origin() - center;
        T a = dot(r.direction(), r.direction());
        T b = static_cast<T>(2.0*dot(oc, r.direction()));
        T c = static_cast<T>(dot(oc, oc) - radius * radius);
        T dis = static_cast<T>(b*b - 4 * a*c);
        if (dis < 0) return -1.0;
        return (-b - sqrt(dis)) / (2.0*a);
    }

    template<typename T>
    vec3<T> color(const ray<T>& r)
    {
        T t = hit_sphere(vec3<T>(0, 0, -1), 0.5, r);
        if (t > 0.0)
        {
            // in the ball
            vec3<T> N = unit_vector(r.point_at_parameter(t) - vec3<T>(0, 0, -1)); // minus normal vector for every point on the surface
            return 0.5*vec3<T>(N.x() + 1, N.y() + 1, N.z() + 1);
        }
        // outside the ball, aka background
        vec3<T> unit_dir = unit_vector(r.direction());
        t = 0.5 * (unit_dir.y() + 1.0);
        return (1.0 - t)*vec3<T>(1.0, 1.0, 1.0) + t * vec3<T>(0.5, 0.7, 1.0);
    }

}

#endif // ! _RAY_H_


