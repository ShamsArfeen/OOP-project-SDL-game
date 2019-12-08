#include "texture.hpp"

class triangle_3d
{
    private:

    public:
        int p1,p2,p3;
        texture_3d texture;
        triangle_3d();
        triangle_3d(int, int, int, texture_3d);
        triangle_3d(const triangle_3d &tri);
};