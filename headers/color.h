#ifndef COLOR_H
#define COLOR_H

#include"vec3.h"
#include <algorithm>
#include<iostream>

using color=vec3;

void write_color(std::ostream& out,const color& pixel_color)
{

    auto r= pixel_color.x();
    auto g=pixel_color.y();
    auto b=pixel_color.z();


    int rbyte = static_cast<int>(256 * std::clamp(r, 0.0, 0.999));
    int gbyte = static_cast<int>(256 * std::clamp(g, 0.0, 0.999));
    int bbyte = static_cast<int>(256 * std::clamp(b, 0.0, 0.999));
    out<<rbyte<<' '<<gbyte<<' '<<bbyte<<' '<<'\n';
}

#endif
