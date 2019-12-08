#include "line_3d.hpp"

line_3d::line_3d()
{
    p1 = 0;
    p2 = 0;
}

line_3d::line_3d(int ip1 = 0, int ip2 = 0)
{
    p1 = ip1;
    p2 = ip2;
}

line_3d::line_3d(const line_3d &li)
{
    p1 = li.p1;
    p2 = li.p2;
}

line_3d::~line_3d()
{
}