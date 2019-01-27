#include <iostream>
#include "ray.h"
#include "ShittyPresent.h"

int main()
{
    // initial setup
    int nx = 200, ny = 100;
    ShittyPresent<int> p(nx, ny);
    FrameBuffer<int> fb;
    
    // draw every pixel onto fb
    vec3<float> lower_left_corner(-2.0, -1.0, -1.0);
    vec3<float> horizontal(4.0, 0.0, 0.0);
    vec3<float> vertical(0.0, 2.0, 0.0);
    vec3<float> origin(0.0, 0.0, 0.0);
    for (int i=ny-1;i>=0;i--)
    {
        for (int j=0;j<nx;j++)
        {
            float u = float(i) / float(nx);
            float v = float(j) / float(ny);
            // from lower left corner, scan through the whole screen
            ray<float> r(origin, lower_left_corner + u*horizontal + v * vertical);
            vec3<float> col = color<float>(r);

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