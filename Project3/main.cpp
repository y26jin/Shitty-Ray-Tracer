#include <iostream>
#include "ray.h"
#include "ShittyPresent.h"
#include "stdafx.h"

#define DX12ASYNCCOMPUTE 0
#define CPUMODE 1
#define RAYMODE CPUMODE

int main()
{
#if RAYMODE == DX12ASYNCCOMPUTE

#elif RAYMODE == CPUMODE
    // initial setup
    int nx{ 200 };
    int ny{ 100 };
    ShittyPresent<int> p(nx, ny);
    FrameBuffer<int> fb;
    
    // draw every pixel onto fb
    vec3<double> lower_left_corner(-2.0, -1.0, -1.0);
    vec3<double> horizontal(4.0, 0.0, 0.0);
    vec3<double> vertical(0.0, 2.0, 0.0);
    vec3<double> origin(0.0, 0.0, 0.0);
    for (int j=ny-1;j>=0;--j)
    {
        for (int i = 0; i < nx; ++i)
        {
            double u = double(i) / double(nx);
            double v = double(j) / double(ny);
            // from lower left corner, scan through the whole screen
            ray<double> r(origin, lower_left_corner + u * horizontal + v * vertical);
            // draw a red ball with blue background
            vec3<double> col = color<double>(r);
            int ir = static_cast<int>(255.99*col[0]);
            int ig = static_cast<int>(255.99*col[1]);
            int ib = static_cast<int>(255.99*col[2]);

            std::vector<int> temp(3, 0);
            temp[0] = ir;
            temp[1] = ig;
            temp[2] = ib;
            fb.push_back(temp);
        }
    }
    // Shitty present
    p.Present(fb);
#endif
    return 0;
}