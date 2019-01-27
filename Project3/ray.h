#pragma once
#ifndef _RAY_H_ 
#define _RAY_H_
#include "vec3.h"

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
vec3<T> color(const ray<T>& r)
{
    vec3<T> unit_direction = unit_vector(r.direction());
    T t = 0.5*(unit_direction.y() + 1.0);
    T start = 1 - t; // (1.0-t) is implicitly converted to double, dont want that
    
    vec3<T> white(1.0, 1.0, 1.0);
    vec3<T> blue(0.5, 0.7, 1.0);
    return start * white + t * blue;
}

#endif // ! _RAY_H_

