#include "3d_matrix.hpp"

const int frames_per_spin = 4;
class rubriks_cube : public matrix
{
private:
public:
    rubriks_cube();
    rubriks_cube(const rubriks_cube &icube);
    ~rubriks_cube();
    void precise_mat();
    void add_triangle(int, int, int, texture_3d);
    bool is_solved();
    virtual void render(float,float) = 0;
    void spin_face(int rot_axis, int floor, int clockwise);
};