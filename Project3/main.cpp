#include <iostream>
#include "ShittyPresent.h"

int main()
{
    // initial setup
    unsigned int nx = 200, ny = 200;
    ShittyPresent<unsigned int> p(nx, ny);
    FrameBuffer fb(nx*ny, std::vector<unsigned int>(3,0));
    
    // draw every pixel onto fb
    unsigned count = 0;
    for (unsigned int i=ny-1;i>0;--i)
    {
        for (unsigned int j=0;j<nx;++j)
        {
            double r = double(j) / double(nx);
            double g = double(i) / double(ny);
            double b = static_cast<double>(0.2);

            unsigned int ir = unsigned int(255.99*r);
            unsigned int ig = unsigned int(255.99*g);
            unsigned int ib = unsigned int(255.99*b);

            fb[count][0] = ir;
            fb[count][1] = ig;
            fb[count][2] = ib;
            count++;
        }
    }

    // present
    p.Present(fb);

    return 0;
}