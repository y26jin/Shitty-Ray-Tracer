#pragma once
#ifndef _SHITTYPRESENT_H_
#define _SHITTYPRESENT_H_

#include <iostream>
#include <fstream>
#include <vector>

namespace CpuMode {

    template<class T>
    using FrameBuffer = std::vector<std::vector<T>>;

    template<class T>
    class ShittyPresent
    {
    public:
        ShittyPresent() {}
        ShittyPresent(int h, int w) {
            x = h;
            y = w;
        }
        ~ShittyPresent() {}

        void Present(const FrameBuffer<T>& p) const {
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
    private:
        int x;
        int y;
    };

}

#endif // ! _SHITTYPRESENT_H_
