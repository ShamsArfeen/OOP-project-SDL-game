#include "rubrik.hpp"
#include <ostream>

rubriks_cube::~rubriks_cube()
{
}

rubriks_cube::rubriks_cube(const rubriks_cube &icube)
{
    point_num = icube.point_num;
    line_num = icube.line_num;
    triangle_num = icube.triangle_num;
    i_point = icube.i_point;
    r_point = new point_3d[icube.point_num];
    i_line = icube.i_line;
    i_triangle = icube.i_triangle;
    surface_color = icube.surface_color;
    screen_pt = new point_2d[icube.point_num];
    x_rotation = 0;
    y_rotation = 0;
    screen_z = new float *[600];
    for (int i = 0; i < 600; i++)
    {
        screen_z[i] = new float[600];
    }
}

int iround(float x)
{
    int y = int(x);
    if (x - y > 0.5)
    {
        return y + 1;
    }
    else if (y - x > 0.5)
    {
        return y - 1;
    }
    return y;
}

void rubriks_cube::add_triangle(int p1, int p2, int p3, texture_3d col_)
{
    triangle_3d *j_triangle = new triangle_3d[triangle_num + 1];
    texture_3d *j_surface_color = new texture_3d[triangle_num + 1];
    for (int i = 0; i < triangle_num; i++)
    {
        j_surface_color[i] = surface_color[i];
        j_triangle[i] = i_triangle[i];
    }
    j_surface_color[triangle_num] = col_;
    j_triangle[triangle_num].p1 = p1;
    j_triangle[triangle_num].p2 = p2;
    j_triangle[triangle_num].p3 = p3;
    delete[] i_triangle;
    delete[] surface_color;
    i_triangle = j_triangle;
    surface_color = j_surface_color;
    triangle_num++;
}

void rubriks_cube::precise_mat()
{
    for (int i = 0; i < point_num; i++)
    {
        i_point[i].x = iround(i_point[i].x);
        i_point[i].y = iround(i_point[i].y);
        i_point[i].z = iround(i_point[i].z);
    }
}

bool rubriks_cube::is_solved()
{
    bool face_x_const;
    bool face_y_const;
    bool face_z_const;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 18; j+=2)
        {
            point_3d p1 = i_point[i_triangle[18 * i + j].p1];
            point_3d p2 = i_point[i_triangle[18 * i + j].p2];
            point_3d p3 = i_point[i_triangle[18 * i + j].p3];

            bool is_x_const = (p1.x == p2.x) && (p2.x == p3.x);
            bool is_y_const = (p1.y == p2.y) && (p2.y == p3.y);
            bool is_z_const = (p1.z == p2.z) && (p2.z == p3.z);

            if (j == 0)
            {
                face_x_const = is_x_const;
                face_y_const = is_y_const;
                face_z_const = is_z_const;
            }
            else
            {
                if (face_x_const != is_x_const || face_y_const != is_y_const || face_z_const != is_z_const)
                {
                    return false;
                }
            }
        }
    }
    return true;
}

void rubriks_cube::spin_face(int rot_axis, int floor, int clockwise)
{
    bool is_x_axis = rot_axis == 0;
    bool is_y_axis = rot_axis == 1;
    bool is_z_axis = rot_axis == 2;
    float *x, *y, *z, i_x, i_y, i_z;
    float rad = (float)half_pi / (float)frames_per_spin;
    for (int i = 3; i < 219; i++)
    {
        if (is_x_axis)
        {
            x = &(i_point[i].y);
            y = &(i_point[i].z);
            z = &(i_point[i].x);
        }
        else if (is_y_axis)
        {
            x = &(i_point[i].x);
            y = &(i_point[i].z);
            z = &(i_point[i].y);
        }
        else if (is_z_axis)
        {
            x = &(i_point[i].x);
            y = &(i_point[i].y);
            z = &(i_point[i].z);
        }
        i_z = *z;
        i_y = *y;
        i_x = *x;
        if (abs(75 * floor - i_z) < 30)
        {
            float hypotenuse = sqrt(i_x * i_x + i_y * i_y);
            float tan_inv = arctan(i_y, i_x) + clockwise * rad;
            i_y = sin(tan_inv) * hypotenuse;
            i_x = cos(tan_inv) * hypotenuse;
            *y = i_y;
            *x = i_x;
        }
    }
}