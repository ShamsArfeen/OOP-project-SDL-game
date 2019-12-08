#include "face.hpp"
#include <iostream>

face::face(SDL_Renderer *iRenderer)
{
    gRenderer = iRenderer;
    spin_command = false;
}

void face::execute_spin(int rot_axis_i, int floor_i, int clockwise_i)
{
    if (spin_command == false && shuffle_moves == 0)
    {
        spin_command = true;
        rot_axis = rot_axis_i;
        floor = floor_i;
        clockwise = clockwise_i;
        spin_frame = 0;
    }
}

void face::render(float x_rotate, float y_rotate)
{
    if (shuffle_moves > 0)
    {
        spin_face(rot_axis, floor, clockwise);
        spin_frame++;
        if (spin_frame == frames_per_spin)
        {
            shuffle_moves--;
            rot_axis = rand() % 3;
            floor = rand() % 3 - 1;
            clockwise = 1;
            precise_mat();
            spin_frame = 0;
        }
    } 
    else if (spin_command)
    {
        spin_face(rot_axis, floor, clockwise);
        spin_frame++;
        if (spin_frame == frames_per_spin)
        {
            spin_command = false;
            precise_mat();
        }
    }
    rotate_mat(x_rotate, y_rotate);
    render_surfaces(gRenderer);
}

void face::shuffle(int moves)
{
    if (shuffle_moves == 0 && spin_command == false)
    {    shuffle_moves = moves;
        spin_frame = 0;
        rot_axis = rand() % 3;
        floor = rand() % 3 - 1;
        clockwise = 1;
    }
}