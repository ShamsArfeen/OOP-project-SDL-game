#include "point_3d.hpp"

point_3d::point_3d()
{
    x=0;
    y=0;
    z=0;
}
point_3d::point_3d(float ix = 0.0, float iy = 0.0, float iz = 0.0)
{
    x = ix;
    y = iy;
    z = iz;
}
point_3d::point_3d(const point_3d &p1)
{
    x = p1.x;
    y = p1.y;
    z = p1.z;
}
point_3d::~point_3d()
{

}