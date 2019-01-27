#include "vec3.h"

#pragma once
#ifndef _VEC3_CPP_
#define _VEC3_CPP_

template<class T>
inline T vec3<T>::dot(const vec3<T> &v1, const vec3<T> &v2)
{
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

template<class T>
inline vec3<T> vec3<T>::cross(const vec3<T> &v1, const vec3<T> &v2)
{
    return vec3(
        (v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1]),
        (v1.e[2] * v2.e[0] - v1.e[0] * v2.e[2]),
        (v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0])
    );
}

template<class T>
inline vec3<T>& vec3<T>::operator+=(const vec3<T> &v)
{
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

template<class T>
inline vec3<T>& vec3<T>::operator*=(const vec3<T> &v)
{
    e[0] *= v.e[0];
    e[1] *= v.e[1];
    e[2] *= v.e[2];
    return *this;
}

template<class T>
inline vec3<T>& vec3<T>::operator/=(const vec3<T> &v)
{
    e[0] /= v.e[0];
    e[1] /= v.e[1];
    e[2] /= v.e[2];
    return *this;
}

template<class T>
inline vec3<T>& vec3<T>::operator-=(const vec3<T> &v)
{
    e[0] -= v.e[0];
    e[1] -= v.e[1];
    e[2] -= v.e[2];
    return *this;
}

template<class T>
inline vec3<T>& vec3<T>::operator*=(const T t)
{
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

template<class T>
inline vec3<T>& vec3<T>::operator/=(const T t)
{
    e[0] /= t;
    e[1] /= t;
    e[2] /= t;
    return *this;
}


template<class T>
inline void vec3<T>::make_unit_vector()
{
    T len = length();
    e[0] /= len;
    e[1] /= len;
    e[2] /= len;
}

#endif // ! _VEC3_CPP_