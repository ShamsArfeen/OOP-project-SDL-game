#include "point_2d.hpp"

point_2d::point_2d()
{
    x=0;
    y=0;
}
point_2d::point_2d(float ix = 0.0, float iy = 0.0)
{
    x = ix;
    y = iy;
}
point_2d::point_2d(const point_2d &p1)
{
    x = p1.x;
    y = p1.y;
}
point_2d::~point_2d()
{

}