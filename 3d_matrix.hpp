#include <math.h>
#include <SDL.h>
#include "point_3d.hpp"
#include "line_3d.hpp"
#include "triangle_3d.hpp"
#include "point_2d.hpp"

const float PI = 3.1415926535897932;
const float half_pi = 1.57079632679489661;
const float aperture = 0.7853981633974483096;
const int eye_z = 1000;
const int eye_size = 500;
const int center_x = 252;
const int center_y = 210;
const int flash_x = 0;
const int flash_y = 0;
const int flash_z = 10;

class matrix
{
private:
public:
    int point_num;
    point_3d *i_point;
    point_3d *r_point;
    point_2d *screen_pt;
    float **screen_z;
    int line_num;
    line_3d *i_line;
    int triangle_num;
    texture_3d *surface_color;
    triangle_3d *i_triangle;
    float tri_a, tri_b, tri_c, tri_d;
    float y_rotation, x_rotation;
    matrix();
    matrix(const matrix &imat);
    void rotate_mat(float, float);
    void render_wireframe(SDL_Renderer *);
    float arctan(float, float);
    void add_point(float, float, float);
    void add_line(int, int);
    virtual void add_triangle(int, int, int, texture_3d);
    void front_view();
    float compute_z(int, int);
    void get_tri_constants(int);
    bool render_surface(int, SDL_Renderer *);
    virtual void precise_mat() = 0;
    virtual void render_surfaces(SDL_Renderer *);
    void add_cube(float, float, float, float, float, float, texture_3d);
    void five_tetrahedrons(float, float, float, float);
    void clear_mat();
    int operator + (point_3d point);
    int operator - (point_3d point);
    int operator + (line_3d line);
    int operator - (line_3d line);
    int operator + (triangle_3d tri);
    int operator - (triangle_3d tri);
    ~matrix();
};