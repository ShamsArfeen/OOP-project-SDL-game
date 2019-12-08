#include "texture.hpp"

texture_3d::texture_3d()
{
    r = 255;
    g = 255;
    b = 255;
}
texture_3d::texture_3d(int ir = 255, int ig = 255, int ib = 255)
{
    r = ir;b = ib;g = ig;
}
texture_3d::texture_3d(const texture_3d &i_col)
{
    r = i_col.r;b = i_col.b;g = i_col.g;
}
texture_3d::~texture_3d(){

}