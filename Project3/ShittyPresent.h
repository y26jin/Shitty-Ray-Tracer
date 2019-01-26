#pragma once
#ifndef _SHITTYPRESENT_H_
#define _SHITTYPRESENT_H_

#include <iostream>
#include <fstream>
#include <vector>

template<typename T>
using FrameBuffer = std::vector<std::vector<T>>;

template<class T>
class ShittyPresent
{
public:
    ShittyPresent() {}
    ShittyPresent(unsigned int h, unsigned int w);
    ~ShittyPresent() {}

    void Present(const FrameBuffer<T>& p) const;
private:
    unsigned int height;
    unsigned int width;
};

#include "ShittyPresent.cpp"

#endif // ! _SHITTYPRESENT_H_
