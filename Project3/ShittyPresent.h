#pragma once
#ifndef _SHITTYPRESENT_H_
#define _SHITTYPRESENT_H_

#include <iostream>
#include <fstream>
#include <vector>

template<class T>
using FrameBuffer = std::vector<std::vector<T>>;

template<class T>
class ShittyPresent
{
public:
    ShittyPresent() {}
    ShittyPresent(int h, int w);
    ~ShittyPresent() {}

    void Present(const FrameBuffer<T>& p) const;
private:
    int x;
    int y;
};

#include "ShittyPresent.cpp"

#endif // ! _SHITTYPRESENT_H_
