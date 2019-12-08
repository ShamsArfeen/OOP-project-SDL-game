class point_2d
{
    private:
        /* data */
    public:
        float x, y;
        point_2d();
        point_2d(float, float);
        point_2d(const point_2d &p1);
        ~point_2d();
};