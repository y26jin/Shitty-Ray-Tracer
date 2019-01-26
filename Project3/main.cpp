#include <iostream>
#include "ShittyPresent.h"

int main()
{
    // initial setup
    int nx = 200, ny = 100;
    ShittyPresent<int> p(nx, ny);
    FrameBuffer<int> fb;
    
    // draw every pixel onto fb
    for (int i=ny-1;i>=0;i--)
    {
        for (int j=0;j<nx;j++)
        {
            float r = float(j) / float(nx);
            float g = float(i) / float(ny);
            float b = 0.2;

            int ir = int(255.99*r);
            int ig = int(255.99*g);
            int ib = int(255.99*b);

            std::vector<int> temp(3, 0);
            temp[0] = ir;
            temp[1] = ig;
            temp[2] = ib;
            fb.push_back(temp);
        }
    }

    // present
    p.Present(fb);

    return 0;
}