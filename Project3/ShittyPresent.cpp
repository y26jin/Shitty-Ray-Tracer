#include "ShittyPresent.h"
#include <fstream>
#include <iostream>
#pragma once

#ifndef _SHITTYPRESENT_CPP_
#define _SHITTYPRESENT_CPP_

template<class T>
ShittyPresent<T>::ShittyPresent(unsigned int h, unsigned int w)
{
    height = h;
    width = w;
}

template<class T>
void ShittyPresent<T>::Present(const FrameBuffer& p) const
{
    // set up PPM image format
    std::ofstream fs("image.ppm");
    fs << "P3\n" << height << " " << width << "\n255\n";
    
    // write from frame buffer to target file
    for (unsigned int i = 0; i < height; ++i)
    {
        for (unsigned int j = 0; j < width; ++j)
        {
            // output every pixel
            fs << p[i*j][0] << " " << p[i*j][1] << " " << p[i*j][2] << "\n";
            std::cout << p[i*j][0] << " " << p[i*j][1] << " " << p[i*j][2] << "\n";
        }
    }
    fs.close();
}

#endif // !_SHITTYPRESENT_CPP_
