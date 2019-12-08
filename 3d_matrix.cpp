#include <iostream>
#include "3d_matrix.hpp"

using namespace std;

matrix::matrix()
{
    point_num = 0;
    line_num = 0;
    triangle_num = 0;
    i_point = NULL;
    r_point = NULL;
    i_line = NULL;
    i_triangle = NULL;
    surface_color = NULL;
    screen_pt = NULL;
    x_rotation = 0;
    y_rotation = 0;
    screen_z = new float *[600];
    for (int i = 0; i < 600; i++)
    {
        screen_z[i] = new float[600];
    }
}

matrix::matrix(const matrix &imat)
{
    point_num = imat.point_num;
    line_num = imat.line_num;
    triangle_num = imat.triangle_num;
    i_point = imat.i_point;
    r_point = new point_3d[imat.point_num];
    i_line = imat.i_line;
    i_triangle = imat.i_triangle;
    surface_color = imat.surface_color;
    screen_pt = new point_2d[imat.point_num];
    x_rotation = 0;
    y_rotation = 0;
    screen_z = new float *[600];
    for (int i = 0; i < 600; i++)
    {
        screen_z[i] = new float[600];
    }
}

void matrix::front_view()
{
    x_rotation = 0;
    y_rotation = 0;
}

void matrix::clear_mat()
{
    point_num = 4;
    line_num = 3;
    i_point = NULL;
    r_point = NULL;
    i_line = NULL;
    screen_pt = NULL;
    x_rotation = 0;
    y_rotation = 0;
}

void matrix::add_point(float x, float y, float z)
{
    point_3d *j_point = new point_3d[point_num + 1];
    delete[] r_point;
    delete[] screen_pt;
    r_point = new point_3d[point_num + 1];
    screen_pt = new point_2d[point_num + 1];
    for (int i = 0; i < point_num; i++)
    {
        j_point[i] = i_point[i];
    }
    j_point[point_num].x = x;
    j_point[point_num].y = y;
    j_point[point_num].z = z;
    delete[] i_point;
    i_point = j_point;
    point_num++;
}

void matrix::add_line(int p1, int p2)
{
    line_3d *j_line = new line_3d[line_num + 1];
    for (int i = 0; i < line_num; i++)
    {
        j_line[i] = i_line[i];
    }
    j_line[line_num].p1 = p1;
    j_line[line_num].p2 = p2;
    delete[] i_line;
    i_line = j_line;
    line_num++;
}

void matrix::add_triangle(int p1, int p2, int p3, texture_3d i_col)
{
    triangle_3d *j_triangle = new triangle_3d[triangle_num + 1];
    texture_3d *j_surface_color = new texture_3d[triangle_num + 1];
    for (int i = 0; i < triangle_num; i++)
    {
        j_surface_color[i] = surface_color[i];
        j_triangle[i] = i_triangle[i];
    }
    j_surface_color[triangle_num] = texture_3d();
    j_triangle[triangle_num].p1 = p1;
    j_triangle[triangle_num].p2 = p2;
    j_triangle[triangle_num].p3 = p3;
    delete[] i_triangle;
    delete[] surface_color;
    i_triangle = j_triangle;
    surface_color = j_surface_color;
    triangle_num++;
}

float matrix::arctan(float y, float x)
{
    return atan2(y, x);
}

void matrix::rotate_mat(float x, float y)
{

    float ptx, pty, ptz;
    float ini_x, ini_y;
    float hypotenuse, k;
    for (int i = 0; i < point_num; i++)
    {
        ptx = i_point[i].x;
        pty = i_point[i].y;
        ptz = i_point[i].z;

        ini_x = arctan(ptz, ptx) - x_rotation - x;
        hypotenuse = sqrt(ptx * ptx + ptz * ptz);
        ptx = cos(ini_x) * hypotenuse;
        ptz = sin(ini_x) * hypotenuse;

        ini_y = arctan(ptz, pty) + y_rotation + y;
        hypotenuse = sqrt(ptz * ptz + pty * pty);
        ptz = sin(ini_y) * hypotenuse;
        pty = cos(ini_y) * hypotenuse;

        r_point[i].x = ptx;
        r_point[i].y = pty;
        r_point[i].z = ptz;

        k = (float)eye_size / (float)(ptz + eye_z);
        screen_pt[i].x = k * ptx;
        screen_pt[i].y = k * pty;
    }
}

void matrix::render_wireframe(SDL_Renderer *g_renderer)
{
    //Clear screen
    SDL_SetRenderDrawColor(g_renderer, 0, 0, 0, 0);
    SDL_RenderClear(g_renderer);
    SDL_SetRenderDrawColor(g_renderer, 255, 255, 255, 255);
    int p1, p2, x1, x2, y1, y2;
    for (int i = 3; i < line_num; i++)
    {
        p1 = i_line[i].p1;
        p2 = i_line[i].p2;

        x1 = int(screen_pt[p1].x) + center_x;
        y1 = -int(screen_pt[p1].y) + center_y;

        x2 = int(screen_pt[p2].x) + center_x;
        y2 = -int(screen_pt[p2].y) + center_y;

        SDL_RenderDrawLine(g_renderer, x1, y1, x2, y2);
    }
    //Update screen
    SDL_RenderPresent(g_renderer);
}

matrix::~matrix()
{
    delete[] i_point;
    delete[] r_point;
    delete[] i_line;
    delete[] i_triangle;
    delete[] surface_color;
    delete[] screen_pt;
    for (int i = 0; i < 600; i++)
    {
        delete[] screen_z[i];
    }
    delete[] screen_z;
}

void matrix::get_tri_constants(int tri)
{
    float pt1x, pt1y, pt1z;
    float pt2x, pt2y, pt2z;
    float pt3x, pt3y, pt3z;

    pt1x = r_point[i_triangle[tri].p1].x;
    pt1y = r_point[i_triangle[tri].p1].y;
    pt1z = r_point[i_triangle[tri].p1].z;
    pt2x = r_point[i_triangle[tri].p2].x;
    pt2y = r_point[i_triangle[tri].p2].y;
    pt2z = r_point[i_triangle[tri].p2].z;
    pt3x = r_point[i_triangle[tri].p3].x;
    pt3y = r_point[i_triangle[tri].p3].y;
    pt3z = r_point[i_triangle[tri].p3].z;

    tri_d = pt1x * pt2z * pt3y - pt2z * pt3x * pt1y - pt1z * pt2x * pt3y + pt2y * pt1z * pt3x + pt2x * pt1y * pt3z - pt1x * pt2y * pt3z;
    tri_c = pt1x * pt3y - pt3x * pt1y - pt2x * pt3y + pt3x * pt2y + pt2x * pt1y - pt1x * pt2y;
    tri_b = pt3x * pt1z - pt1x * pt3z + pt2x * pt3z - pt3x * pt2z - pt2x * pt1z + pt1x * pt2z;
    tri_a = pt3z * pt1y - pt1z * pt3y + pt2z * pt3y - pt3z * pt2y - pt2z * pt1y + pt1z * pt2y;
}

int comparison(float a)
{
    if (a == 0)
    {
        return 0;
    }
    else if (a > 0)
    {
        return 1;
    }
    return -1;
}

int max_in(int a, int b, int c)
{
    if (a >= b)
    {
        if (a >= c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b >= c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}

int min_in(int a, int b, int c)
{
    if (a <= b)
    {
        if (a <= c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if (b <= c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}

int color_range(float x)
{
    if (x > 255)
    {
        return 255;
    }
    return x;
}

float non_zero(float x)
{
    if (abs(x) < 1)
    {
        return 1;
    }
    return x;
}

float matrix::compute_z(int x, int y)
{
    return (float)(-eye_size * tri_d + eye_z * tri_a * (x - center_x) + eye_z * tri_b * (center_y - y)) / (float)non_zero(tri_a * (x - center_x) + tri_b * (center_y - y) + tri_c * eye_size);
}

void matrix::render_surfaces(SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 0);
    SDL_RenderClear(gRenderer);
    for (int i = 0; i < 600; i++)
    {
        for (int j = 0; j < 600; j++)
        {
            screen_z[i][j] = NULL;
        }
    }
    for (int i = 0; i < triangle_num; i++)
    {
        render_surface(i, gRenderer);
    }
    SDL_RenderPresent(gRenderer);
}

bool matrix::render_surface(int tri, SDL_Renderer *g_Renderer)
{
    get_tri_constants(tri);
    float flash = sqrt(flash_x * flash_x + flash_y * flash_y + flash_z * flash_z);
    float triangle = sqrt(tri_a * tri_a + tri_b * tri_b + tri_c * tri_c);
    float reflection = abs(flash_x * tri_a + flash_y * tri_b + flash_z * tri_c);
    float shine = abs(asin(reflection / (triangle * flash)));
    if (shine < 0.15)
    {
        return false;
    }
    int texture = color_range(140 * shine + 30);
    texture_3d i_col = surface_color[tri];
    SDL_SetRenderDrawColor(g_Renderer, (i_col.r * texture) / 255, (i_col.g * texture) / 255, (i_col.b * texture) / 255, 255);

    int x1, x2, x3, y1, y2, y3;
    x1 = screen_pt[i_triangle[tri].p1].x + center_x;
    x2 = screen_pt[i_triangle[tri].p2].x + center_x;
    x3 = screen_pt[i_triangle[tri].p3].x + center_x;
    y1 = -screen_pt[i_triangle[tri].p1].y + center_y;
    y2 = -screen_pt[i_triangle[tri].p2].y + center_y;
    y3 = -screen_pt[i_triangle[tri].p3].y + center_y;

    int max_x, min_x, max_y, min_y;
    max_x = max_in(x1, x2, x3);
    min_x = min_in(x1, x2, x3);
    max_y = max_in(y1, y2, y3);
    min_y = min_in(y1, y2, y3);

    if (min_x == max_x)
    {
        max_x++;
    }
    if (min_y == max_y)
    {
        max_y++;
    }
    for (int x = min_x; x <= max_x; x++)
    {
        for (int y = min_y; y <= max_y; y++)
        {
            float a12, b12, c12;
            a12 = y2 - y1;
            b12 = x1 - x2;
            c12 = x2 * y1 - x1 * y2;

            float a13, b13, c13;
            a13 = y3 - y1;
            b13 = x1 - x3;
            c13 = x3 * y1 - x1 * y3;

            float a32, b32, c32;
            a32 = y2 - y3;
            b32 = x3 - x2;
            c32 = x2 * y3 - x3 * y2;

            bool cond1, cond2, cond3;
            cond1 = comparison(a12 * x + b12 * y + c12) == comparison(a12 * x3 + b12 * y3 + c12) | a12 * x + b12 * y + c12 == 0;
            cond2 = comparison(a13 * x + b13 * y + c13) == comparison(a13 * x2 + b13 * y2 + c13) | a13 * x + b13 * y + c13 == 0;
            cond3 = comparison(a32 * x + b32 * y + c32) == comparison(a32 * x1 + b32 * y1 + c32) | a32 * x + b32 * y + c32 == 0;
            if (cond1 && cond2 && cond3)
            {
                float i_screen_z = compute_z(x, y);
                if (screen_z[x][y] != NULL)
                {
                    if (screen_z[x][y] < i_screen_z)
                    {
                        SDL_RenderDrawPoint(g_Renderer, x, y);
                        screen_z[x][y] = i_screen_z;
                    }
                }
                else
                {
                    SDL_RenderDrawPoint(g_Renderer, x, y);
                    screen_z[x][y] = i_screen_z;
                }
            }
        }
    }
    return true;
}