#include "triangle_3d.hpp"


triangle_3d::triangle_3d()
{
    p1 = 0;
    p2 = 0;
    p3 = 0;
}

triangle_3d::triangle_3d(int i1, int i2, int i3, texture_3d i_col)
{
    p1 = i1;
    p2 = i2;
    p3 = i3;
    texture = i_col;
}

triangle_3d::triangle_3d(const triangle_3d &tri)
{
    p1 = tri.p1;
    p2 = tri.p2;
    p3 = tri.p3;
    texture = tri.texture;
}