#include "rubrik.hpp"

rubriks_cube::rubriks_cube()
{
    //xyz axis

    /*this->add_point(1, 0, 0);
    this->add_point(0, 1, 0);
    this->add_point(0, 0, 1);*/
    point_3d px(1,0,0);
    *this + px;
    point_3d py(0,1,0);
    *this + py;
    point_3d pz(0,0,1);
    *this + pz;

    texture_3d i_col;
    i_col.r = 255;
    i_col.g = 255;
    i_col.b = 0;

    //yellow
    this->add_point(-100, 25, 25);
    this->add_point(-100, -25, 25);
    this->add_point(-100, 25, -25);
    this->add_point(-100, -25, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 100, 100);
    this->add_point(-100, 50, 100);
    this->add_point(-100, 100, 50);
    this->add_point(-100, 50, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, -100, 100);
    this->add_point(-100, -50, 100);
    this->add_point(-100, -100, 50);
    this->add_point(-100, -50, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 100, -100);
    this->add_point(-100, 50, -100);
    this->add_point(-100, 100, -50);
    this->add_point(-100, 50, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, -100, -100);
    this->add_point(-100, -50, -100);
    this->add_point(-100, -100, -50);
    this->add_point(-100, -50, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 25, 100);
    this->add_point(-100, -25, 100);
    this->add_point(-100, 25, 50);
    this->add_point(-100, -25, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 100, 25);
    this->add_point(-100, 50, 25);
    this->add_point(-100, 100, -25);
    this->add_point(-100, 50, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, -100, 25);
    this->add_point(-100, -50, 25);
    this->add_point(-100, -100, -25);
    this->add_point(-100, -50, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 25, -100);
    this->add_point(-100, -25, -100);
    this->add_point(-100, 25, -50);
    this->add_point(-100, -25, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    i_col.r = 0;
    i_col.g = 255;
    i_col.b = 0;
    //green
    this->add_point(25, -100, 25);
    this->add_point(25, -100, -25);
    this->add_point(-25, -100, 25);
    this->add_point(-25, -100, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, -100, 100);
    this->add_point(100, -100, 50);
    this->add_point(50, -100, 100);
    this->add_point(50, -100, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, -100, -100);
    this->add_point(100, -100, -50);
    this->add_point(50, -100, -100);
    this->add_point(50, -100, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, -100, 100);
    this->add_point(-100, -100, 50);
    this->add_point(-50, -100, 100);
    this->add_point(-50, -100, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, -100, -100);
    this->add_point(-100, -100, -50);
    this->add_point(-50, -100, -100);
    this->add_point(-50, -100, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, -100, 25);
    this->add_point(100, -100, -25);
    this->add_point(50, -100, 25);
    this->add_point(50, -100, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(25, -100, 100);
    this->add_point(25, -100, 50);
    this->add_point(-25, -100, 100);
    this->add_point(-25, -100, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(25, -100, -100);
    this->add_point(25, -100, -50);
    this->add_point(-25, -100, -100);
    this->add_point(-25, -100, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, -100, 25);
    this->add_point(-100, -100, -25);
    this->add_point(-50, -100, 25);
    this->add_point(-50, -100, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    i_col.r = 255;
    i_col.g = 0;
    i_col.b = 0;
    //red
    this->add_point(100, 25, 25);
    this->add_point(100, -25, 25);
    this->add_point(100, 25, -25);
    this->add_point(100, -25, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 100, 100);
    this->add_point(100, 50, 100);
    this->add_point(100, 100, 50);
    this->add_point(100, 50, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, -100, 100);
    this->add_point(100, -50, 100);
    this->add_point(100, -100, 50);
    this->add_point(100, -50, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 100, -100);
    this->add_point(100, 50, -100);
    this->add_point(100, 100, -50);
    this->add_point(100, 50, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, -100, -100);
    this->add_point(100, -50, -100);
    this->add_point(100, -100, -50);
    this->add_point(100, -50, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 25, 100);
    this->add_point(100, -25, 100);
    this->add_point(100, 25, 50);
    this->add_point(100, -25, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 100, 25);
    this->add_point(100, 50, 25);
    this->add_point(100, 100, -25);
    this->add_point(100, 50, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, -100, 25);
    this->add_point(100, -50, 25);
    this->add_point(100, -100, -25);
    this->add_point(100, -50, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 25, -100);
    this->add_point(100, -25, -100);
    this->add_point(100, 25, -50);
    this->add_point(100, -25, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    i_col.r = 0;
    i_col.g = 0;
    i_col.b = 255;
    //blue

    this->add_point(25, 100, 25);
    this->add_point(25, 100, -25);
    this->add_point(-25, 100, 25);
    this->add_point(-25, 100, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 100, 100);
    this->add_point(100, 100, 50);
    this->add_point(50, 100, 100);
    this->add_point(50, 100, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 100, -100);
    this->add_point(100, 100, -50);
    this->add_point(50, 100, -100);
    this->add_point(50, 100, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 100, 100);
    this->add_point(-100, 100, 50);
    this->add_point(-50, 100, 100);
    this->add_point(-50, 100, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 100, -100);
    this->add_point(-100, 100, -50);
    this->add_point(-50, 100, -100);
    this->add_point(-50, 100, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 100, 25);
    this->add_point(100, 100, -25);
    this->add_point(50, 100, 25);
    this->add_point(50, 100, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(25, 100, 100);
    this->add_point(25, 100, 50);
    this->add_point(-25, 100, 100);
    this->add_point(-25, 100, 50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(25, 100, -100);
    this->add_point(25, 100, -50);
    this->add_point(-25, 100, -100);
    this->add_point(-25, 100, -50);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 100, 25);
    this->add_point(-100, 100, -25);
    this->add_point(-50, 100, 25);
    this->add_point(-50, 100, -25);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    i_col.r = 255;
    i_col.g = 0;
    i_col.b = 255;
    //magenta

    this->add_point(25, 25, 100);
    this->add_point(25, -25, 100);
    this->add_point(-25, 25, 100);
    this->add_point(-25, -25, 100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 100, 100);
    this->add_point(100, 50, 100);
    this->add_point(50, 100, 100);
    this->add_point(50, 50, 100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, -100, 100);
    this->add_point(100, -50, 100);
    this->add_point(50, -100, 100);
    this->add_point(50, -50, 100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 100, 100);
    this->add_point(-100, 50, 100);
    this->add_point(-50, 100, 100);
    this->add_point(-50, 50, 100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, -100, 100);
    this->add_point(-100, -50, 100);
    this->add_point(-50, -100, 100);
    this->add_point(-50, -50, 100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 25, 100);
    this->add_point(100, -25, 100);
    this->add_point(50, 25, 100);
    this->add_point(50, -25, 100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(25, 100, 100);
    this->add_point(25, 50, 100);
    this->add_point(-25, 100, 100);
    this->add_point(-25, 50, 100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(25, -100, 100);
    this->add_point(25, -50, 100);
    this->add_point(-25, -100, 100);
    this->add_point(-25, -50, 100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 25, 100);
    this->add_point(-100, -25, 100);
    this->add_point(-50, 25, 100);
    this->add_point(-50, -25, 100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    i_col.r = 0;
    i_col.g = 255;
    i_col.b = 255;
    //cyan

    this->add_point(25, 25, -100);
    this->add_point(25, -25, -100);
    this->add_point(-25, 25, -100);
    this->add_point(-25, -25, -100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 100, -100);
    this->add_point(100, 50, -100);
    this->add_point(50, 100, -100);
    this->add_point(50, 50, -100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, -100, -100);
    this->add_point(100, -50, -100);
    this->add_point(50, -100, -100);
    this->add_point(50, -50, -100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 100, -100);
    this->add_point(-100, 50, -100);
    this->add_point(-50, 100, -100);
    this->add_point(-50, 50, -100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, -100, -100);
    this->add_point(-100, -50, -100);
    this->add_point(-50, -100, -100);
    this->add_point(-50, -50, -100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(100, 25, -100);
    this->add_point(100, -25, -100);
    this->add_point(50, 25, -100);
    this->add_point(50, -25, -100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(25, 100, -100);
    this->add_point(25, 50, -100);
    this->add_point(-25, 100, -100);
    this->add_point(-25, 50, -100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(25, -100, -100);
    this->add_point(25, -50, -100);
    this->add_point(-25, -100, -100);
    this->add_point(-25, -50, -100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    this->add_point(-100, 25, -100);
    this->add_point(-100, -25, -100);
    this->add_point(-50, 25, -100);
    this->add_point(-50, -25, -100);

    this->add_triangle(point_num - 1, point_num - 2, point_num - 3, i_col);
    this->add_triangle(point_num - 4, point_num - 3, point_num - 2, i_col);

    i_col.r = 70;
    i_col.g = 70;
    i_col.b = 70;
    this->add_cube(0,0,0,140,140,140,i_col);
}
