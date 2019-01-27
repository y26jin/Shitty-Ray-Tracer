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
    inline T x() const { return e[0]; }
    inline T y() const { return e[1]; }
    inline T z() const { return e[2]; }
    inline T r() const { return e[0]; }
    inline T g() const { return e[1]; }
    inline T b() const { return e[2]; }

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

    inline T length() const { return sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]) };
    inline T squared_length() const { return e[0] * e[0] + e[1] * e[1] + e[2] * e[2]; }

    inline vec3 unit_vector(vec3 v)
    {
        return v / v.length();
    }
    inline T dot(const vec3 &v1, const vec3 &v2);
    inline vec3 cross(const vec3 &v1, const vec3 &v2);
    inline void make_unit_vector();

    T e[3] = { 0 };
};

#include "vec3.cpp"

#endif // ! _VEC3_H_