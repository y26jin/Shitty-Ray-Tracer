
#pragma once

#ifndef _SHITTYPRESENT_CPP_
#define _SHITTYPRESENT_CPP_

#include "ShittyPresent.h"
#include <fstream>
#include <iostream>

template<class T>
ShittyPresent<T>::ShittyPresent(int h, int w)
{
    x = h;
    y = w;
}

template<class T>
void ShittyPresent<T>::Present(const FrameBuffer<T>& p) const
{
    // set up PPM image format
    std::ofstream fs("image.ppm");
    fs << "P3\n" << x << " " << y << "\n255\n";
    
    // write from frame buffer to target file
    for (auto c : p)
    {
        fs << c[0] << " " << c[1] << " " << c[2] << "\n";
    }
    fs.close();
}

#endif // !_SHITTYPRESENT_CPP_
