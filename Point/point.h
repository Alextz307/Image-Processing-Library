#ifndef POINT_H
#define POINT_H

class Point {
    private:
        int x;
        int y;

    public:
        Point(); 

        Point(int x, int y); 

        int get_x() const;

        void set_x(int x);

        int get_y() const;

        void set_y(int y);
};

#endif 