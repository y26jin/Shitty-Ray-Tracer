#pragma once
#ifndef _SHITTYPRESENT_H_
#define _SHITTYPRESENT_H_



#include <iostream>
#include <fstream>
#include <vector>

typedef std::vector<std::vector<unsigned int>> FrameBuffer;

template<class T>
class ShittyPresent
{
public:
    ShittyPresent() {}
    ShittyPresent(unsigned int h, unsigned int w);
    ~ShittyPresent() {}

    void Present(const FrameBuffer& p) const;
private:
    unsigned int height;
    unsigned int width;
};

#include "ShittyPresent.cpp"

#endif // ! _SHITTYPRESENT_H_
