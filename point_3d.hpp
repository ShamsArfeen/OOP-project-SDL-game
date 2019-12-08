class point_3d
{
    private:
        /* data */
    public:
        float x, y, z;
        point_3d();
        point_3d(float, float, float);
        point_3d(const point_3d &p1);
        ~point_3d();
};