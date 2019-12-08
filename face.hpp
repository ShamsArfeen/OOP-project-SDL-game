#include "rubrik.hpp"

class face : public rubriks_cube
{
private:
    int rot_axis;
    int floor;
    int clockwise;
    int spin_frame;
    bool spin_command;
    int shuffle_moves;
    SDL_Renderer *gRenderer;

public:
    face(SDL_Renderer*);
    void execute_spin(int rot_axis_i, int floor_i, int clockwise_i);
    void shuffle(int);
    void render(float, float);
    void rotate_front();
    void rotate_top();
    void rotate_middle_y();
    void rotate_bottom();
    void rotate_right();
    void rotate_middle_x();
    void rotate_left();
};