class texture_3d
{
    private:
    public:
        int r,g,b;
        texture_3d();
        texture_3d(int, int, int);
        texture_3d(const texture_3d &i_col);
        ~texture_3d();
};