#include "face.hpp"


void face::rotate_front()
{
    float z0 = r_point[0].z;
    float z1 = r_point[1].z;
    float z2 = r_point[2].z; 
    if (abs(z0) > abs(z1))
    {
        if (abs(z0) > abs(z2))
        {
            if (z0 > 0) execute_spin(0, -1, 1);
            else  execute_spin(0, 1, 1);
        }
        else
        {
            if (z2 > 0) execute_spin(2, -1, 1);
            else  execute_spin(2, 1, 1);
        }
    }
    else
    {
        if (abs(z1) > abs(z2))
        {
            if (z1 > 0) execute_spin(1, -1, 1);
            else  execute_spin(1, 1, 1);
        }
        else
        {
            if (z2 > 0) execute_spin(2, -1, 1);
            else  execute_spin(2, 1, 1);
        }
    }
}

void face::rotate_top()
{
    float y0 = r_point[0].y;
    float y1 = r_point[1].y;
    float y2 = r_point[2].y; 
    if (abs(y0) > abs(y1))
    {
        if (abs(y0) > abs(y2))
        {
            if (y0 > 0) execute_spin(0, 1, 1);
            else  execute_spin(0, -1, 1);
        }
        else
        {
            if (y2 > 0) execute_spin(2, 1, 1);
            else  execute_spin(2, -1, 1);
        }
    }
    else
    {
        if (abs(y1) > abs(y2))
        {
            if (y1 > 0) execute_spin(1, 1, 1);
            else  execute_spin(1, -1, 1);
        }
        else
        {
            if (y2 > 0) execute_spin(2, 1, 1);
            else  execute_spin(2, -1, 1);
        }
    }
}

void face::rotate_middle_y()
{
    float y0 = r_point[0].y;
    float y1 = r_point[1].y;
    float y2 = r_point[2].y; 
    if (abs(y0) > abs(y1))
    {
        if (abs(y0) > abs(y2))
        {
            execute_spin(0, 0, 1);
        }
        else
        {
            execute_spin(2, 0, 1);
        }
    }
    else
    {
        if (abs(y1) > abs(y2))
        {
            execute_spin(1, 0, 1);
        }
        else
        {
            execute_spin(2, 0, 1);
        }
    }
}

void face::rotate_bottom()
{
    float y0 = r_point[0].y;
    float y1 = r_point[1].y;
    float y2 = r_point[2].y; 
    if (abs(y0) > abs(y1))
    {
        if (abs(y0) > abs(y2))
        {
            if (y0 > 0) execute_spin(0, -1, 1);
            else  execute_spin(0, 1, 1);
        }
        else
        {
            if (y2 > 0) execute_spin(2, -1, 1);
            else  execute_spin(2, 1, 1);
        }
    }
    else
    {
        if (abs(y1) > abs(y2))
        {
            if (y1 > 0) execute_spin(1, -1, 1);
            else  execute_spin(1, 1, 1);
        }
        else
        {
            if (y2 > 0) execute_spin(2, -1, 1);
            else  execute_spin(2, 1, 1);
        }
    }
}

void face::rotate_right()
{
    float x0 = r_point[0].x;
    float x1 = r_point[1].x;
    float x2 = r_point[2].x; 
    if (abs(x0) > abs(x1))
    {
        if (abs(x0) > abs(x2))
        {
            if (x0 > 0) execute_spin(0, 1, 1);
            else  execute_spin(0, -1, 1);
        }
        else
        {
            if (x2 > 0) execute_spin(2, 1, 1);
            else  execute_spin(2, -1, 1);
        }
    }
    else
    {
        if (abs(x1) > abs(x2))
        {
            if (x1 > 0) execute_spin(1, 1, 1);
            else  execute_spin(1, -1, 1);
        }
        else
        {
            if (x2 > 0) execute_spin(2, 1, 1);
            else  execute_spin(2, -1, 1);
        }
    }
}

void face::rotate_middle_x()
{
    float x0 = r_point[0].x;
    float x1 = r_point[1].x;
    float x2 = r_point[2].x; 
    if (abs(x0) > abs(x1))
    {
        if (abs(x0) > abs(x2))
        {
            execute_spin(0, 0, 1);
        }
        else
        {
            execute_spin(2, 0, 1);
        }
    }
    else
    {
        if (abs(x1) > abs(x2))
        {
            execute_spin(1, 0, 1);
        }
        else
        {
            execute_spin(2, 0, 1);
        }
    }
}

void face::rotate_left()
{
    float x0 = r_point[0].x;
    float x1 = r_point[1].x;
    float x2 = r_point[2].x; 
    if (abs(x0) > abs(x1))
    {
        if (abs(x0) > abs(x2))
        {
            if (x0 > 0) execute_spin(0, -1, 1);
            else  execute_spin(0, 1, 1);
        }
        else
        {
            if (x2 > 0) execute_spin(2, -1, 1);
            else  execute_spin(2, 1, 1);
        }
    }
    else
    {
        if (abs(x1) > abs(x2))
        {
            if (x1 > 0) execute_spin(1, -1, 1);
            else  execute_spin(1, 1, 1);
        }
        else
        {
            if (x2 > 0) execute_spin(2, -1, 1);
            else  execute_spin(2, 1, 1);
        }
    }
}