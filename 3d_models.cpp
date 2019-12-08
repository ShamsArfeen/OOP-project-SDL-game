#include <iostream>
#include "3d_matrix.hpp"

void matrix::add_cube(float pos_x, float pos_y, float pos_z, float i_width, float i_height, float i_depth, texture_3d icol)
{
    int i = this->point_num;
    float width = (float)i_width / 2.0;
    float height = (float)i_height / 2.0;
    float depth = (float)i_depth / 2.0;

    this->add_point(pos_x + width, pos_y + height, pos_z + depth); //0
    this->add_point(pos_x + width, pos_y + height, pos_z - depth); //1
    this->add_point(pos_x + width, pos_y - height, pos_z + depth); //2
    this->add_point(pos_x - width, pos_y + height, pos_z + depth); //3
    this->add_point(pos_x - width, pos_y - height, pos_z + depth); //4
    this->add_point(pos_x + width, pos_y - height, pos_z - depth); //5
    this->add_point(pos_x - width, pos_y + height, pos_z - depth); //6
    this->add_point(pos_x - width, pos_y - height, pos_z - depth); //7

    this->add_triangle(i+0,i+1,i+2,icol);
    this->add_triangle(i+0,i+3,i+2,icol);
    this->add_triangle(i+0,i+1,i+3,icol);

    this->add_triangle(i+7,i+6,i+5,icol);
    this->add_triangle(i+7,i+4,i+5,icol);
    this->add_triangle(i+7,i+4,i+6,icol);
    
    this->add_triangle(i+5,i+1,i+2,icol);
    this->add_triangle(i+4,i+3,i+2,icol);
    this->add_triangle(i+6,i+1,i+3,icol);
    
    this->add_triangle(i+1,i+6,i+5,icol);
    this->add_triangle(i+2,i+4,i+5,icol);
    this->add_triangle(i+3,i+4,i+6,icol);
    
    /*this->add_line(i + 0, i + 1);
    this->add_line(i + 0, i + 2);
    this->add_line(i + 0, i + 3);
    this->add_line(i + 2, i + 5);
    this->add_line(i + 7, i + 6);
    this->add_line(i + 3, i + 4);
    this->add_line(i + 3, i + 6);
    this->add_line(i + 5, i + 1);
    this->add_line(i + 6, i + 1);
    this->add_line(i + 4, i + 7);
    this->add_line(i + 4, i + 2);
    this->add_line(i + 5, i + 7);*/
}

void matrix::five_tetrahedrons(float px, float py, float pz, float l)
{
    int i = this->point_num;
    this->add_point(0 + px, 300 + py, 0 + pz);
    this->add_point(0 + px, -300 + py, 0 + pz);
    this->add_point(0 + px, 100 + py, 282 + pz);
    this->add_point(244 + px, 100 + py, -142 + pz);
    this->add_point(-245 + px, 100 + py, -142 + pz);
    this->add_point(-123 + px, 223 + py, 158 + pz);
    this->add_point(198 + px, 223 + py, 27 + pz);
    this->add_point(-76 + px, 223 + py, -186 + pz);
    this->add_point(-274 + px, 100 + py, 70 + pz);
    this->add_point(198 + px, 100 + py, 201 + pz);
    this->add_point(75 + px, 100 + py, -273 + pz);
    this->add_point(-199 + px, -101 + py, -202 + pz);
    this->add_point(-245 + px, -100 + py, 141 + pz);
    this->add_point(-199 + px, -224 + py, -28 + pz);
    this->add_point(-76 + px, -100 + py, 272 + pz);
    this->add_point(244 + px, -101 + py, 141 + pz);
    this->add_point(75 + px, -224 + py, 185 + pz);
    this->add_point(273 + px, -100 + py, -71 + pz);
    this->add_point(-1 + px, -100 + py, -283 + pz);
    this->add_point(122 + px, -224 + py, -159 + pz);
    //tetrahedron
    this->add_line(i + 17, 14 + i);
    this->add_line(i + 0, 14 + i);
    this->add_line(i + 17, 0 + i);
    this->add_line(i + 11, 14 + i);
    this->add_line(i + 11, 0 + i);
    this->add_line(i + 11, 17 + i);
    //tetrahedron
    this->add_line(i + 10, 13 + i);
    this->add_line(i + 15, 13 + i);
    this->add_line(i + 10, 15 + i);
    this->add_line(i + 5, 13 + i);
    this->add_line(i + 5, 15 + i);
    this->add_line(i + 5, 10 + i);
    //tetrahedron
    this->add_line(i + 8, 16 + i);
    this->add_line(i + 18, 16 + i);
    this->add_line(i + 8, 18 + i);
    this->add_line(i + 6, 16 + i);
    this->add_line(i + 6, 18 + i);
    this->add_line(i + 6, 8 + i);
    //tetrahedron
    this->add_line(i + 9, 12 + i);
    this->add_line(i + 19, 12 + i);
    this->add_line(i + 9, 19 + i);
    this->add_line(i + 7, 12 + i);
    this->add_line(i + 7, 19 + i);
    this->add_line(i + 7, 9 + i);
    //tetrahedron
    this->add_line(i + 2, 1 + i);
    this->add_line(i + 3, 1 + i);
    this->add_line(i + 2, 3 + i);
    this->add_line(i + 4, 1 + i);
    this->add_line(i + 4, 3 + i);
    this->add_line(i + 4, 2 + i);
}

int matrix::operator + (point_3d point)
{
    int count = this->operator - (point);
    this->add_point(point.x, point.y, point.z);
    return count;
}
int matrix::operator - (point_3d point)
{
    if (point_num == 0)
        return 0;
    int count = 0;
    for (int i = point_num - 1; i > -1 ; i--)
    {
        if (i_point[i].x == point.x && i_point[i].y == point.y && i_point[i].z == point.z)
        {
            count ++;
            for (int j = i; j < point_num-1; j++)
            {
                i_point[j] = i_point[j+1];

            }
            point_num--;
        }
    }
    return count;
}

int matrix::operator + (line_3d line)
{
    int count = this->operator - (line);
    this->add_line(line.p1, line.p2);
    return count;
}

int matrix::operator - (line_3d line)
{   
    if (line_num == 0)
        return 0;
    int count = 0;
    for (int i = line_num - 1; i > -1 ; i--)
    {
        if (i_line[i].p1 == line.p1 && i_line[i].p2 == line.p2)
        {
            count ++;
            for (int j = i; j < line_num-1; j++)
            {
                i_line[j] = i_line[j+1];

            }
            line_num--;
        }
    }
    return count;
}

int matrix::operator + (triangle_3d tri)
{
    int count = this->operator - (tri);
    this->add_triangle(tri.p1, tri.p2, tri.p3, tri.texture);
    return count;
}

int matrix::operator - (triangle_3d tri)
{
    if (triangle_num == 0)
        return 0;
    int count = 0;
    for (int i = triangle_num - 1; i > -1 ; i--)
    {
        if (i_triangle[i].p1 == tri.p1 && i_triangle[i].p2 == tri.p2 && i_triangle[i].p3 == tri.p3)
        {
            count ++;
            for (int j = i; j < triangle_num-1; j++)
            {
                i_triangle[j] = i_triangle[j+1];

            }
            triangle_num--;
        }
    }
    return count;
}