#pragma once
#ifndef _VEC3_H_
#define _VEC3_H_

#include <iostream>
#include <cmath>
#include <cstdlib>


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

    inline vec3& operator+=(const vec3& v);
    inline vec3& operator-=(const vec3& v);
    inline vec3& operator*=(const vec3& v);
    inline vec3& operator/=(const vec3& v);
    inline vec3& operator*=(const T t);
    inline vec3& operator/=(const T t);

    inline T length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
    inline T squared_length() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

    inline void make_unit_vector();

    T e[3] = { 0 };
};

#include "vec3.cpp"

#endif // ! _VEC3_H_