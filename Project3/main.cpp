#include <iostream>
#include "vec3.h"
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
            vec3<float> col(float(i) / float(nx), float(j) / float(ny), 0.2);

            int ir = int(255.99*col[0]);
            int ig = int(255.99*col[1]);
            int ib = int(255.99*col[2]);

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