#pragma once
#ifndef _VEC3_H_
#define _VEC3_H_

#include <iostream>
#include <cmath>
#include <cstdlib>

namespace CpuMode {

    template<class T>
    class vec3
    {
    public:
        vec3() {};
        ~vec3() {};

        vec3(T e0, T e1, T e2) { e[0] = e0; e[1] = e1; e[2] = e2; }
        inline constexpr T x() const { return e[0]; }
        inline constexpr T y() const { return e[1]; }
        inline constexpr T z() const { return e[2]; }
        inline constexpr T r() const { return e[0]; }
        inline constexpr T g() const { return e[1]; }
        inline constexpr T b() const { return e[2]; }

        inline const vec3& operator+() const { return *this; }
        inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        inline T operator[](int i) const { return e[i]; }
        inline T& operator[](int i) { return e[i]; }

        inline vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }
        inline vec3& operator-=(const vec3& v) {
            e[0] -= v.e[0];
            e[1] -= v.e[1];
            e[2] -= v.e[2];
            return *this;
        }
        inline vec3& operator*=(const vec3& v) {
            e[0] *= v.e[0];
            e[1] *= v.e[1];
            e[2] *= v.e[2];
            return *this;
        }
        inline vec3& operator/=(const vec3& v) {
            e[0] /= v.e[0];
            e[1] /= v.e[1];
            e[2] /= v.e[2];
            return *this;
        }
        inline vec3& operator*=(const T t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }
        inline vec3& operator/=(const T t) {
            e[0] /= t;
            e[1] /= t;
            e[2] /= t;
            return *this;
        }

        inline T length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
        inline T squared_length() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

        inline void make_unit_vector() {
            T len = length();
            e[0] /= len;
            e[1] /= len;
            e[2] /= len;
        }

        T e[3] = { 0 };
    };

    template<class T>
    inline vec3<T> unit_vector(const vec3<T>& v)
    {
        return v / v.length();
    }

    template<class T>
    inline T dot(const vec3<T> &v1, const vec3<T> &v2)
    {
        return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
    }

    template<class T>
    inline vec3<T> cross(const vec3<T> &v1, const vec3<T> &v2)
    {
        return vec3(
            (v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
            (v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2]),
            (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0])
        );
    }

    template<class T>
    inline vec3<T> operator*(const vec3<T>& v, T t)
    {
        return vec3<T>(v.e[0] * t, v.e[1] * t, v.e[2] * t);
    }


    template<typename T>
    inline vec3<T> operator*(T t, const vec3<T>& v)
    {
        return vec3<T>(v.e[0] * t, v.e[1] * t, v.e[2] * t);
    }

    template<typename T>
    inline vec3<T> operator+(const vec3<T>& v1, const vec3<T>& v2)
    {
        return vec3<T>(v1.e[0] + v2.e[0], v1.e[1] + v2.e[1], v1.e[2] + v2.e[2]);
    }

    template<typename T>
    inline vec3<T> operator-(const vec3<T>& v1, const vec3<T>& v2)
    {
        return vec3<T>(v1.e[0] - v2.e[0], v1.e[1] - v2.e[1], v1.e[2] - v2.e[2]);
    }

    template<typename T>
    inline vec3<T> operator*(const vec3<T>& v1, const vec3<T>& v2)
    {
        return vec3<T>(v1.e[0] * v2.e[0], v1.e[1] * v2.e[1], v1.e[2] * v2.e[2]);
    }

    template<typename T>
    inline vec3<T> operator/(const vec3<T>& v1, const vec3<T>& v2)
    {
        return vec3<T>(v1.e[0] / v2.e[0], v1.e[1] / v2.e[1], v1.e[2] / v2.e[2]);
    }

    template<typename T>
    inline vec3<T> operator/(const vec3<T>& v1, T t)
    {
        return vec3<T>(v1.e[0] / t, v1.e[1] / t, v1.e[2] / t);
    }

};
#endif // ! _VEC3_H_