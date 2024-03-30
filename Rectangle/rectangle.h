#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Point/point.h"

class Rectangle {
private:
    int x;
    int y;
    unsigned int width;
    unsigned int height;

public:
    Rectangle();

    Rectangle(int x, int y, unsigned int width, unsigned int height);

    int get_x() const;

    void set_x(int x);

    int get_y() const;

    void set_y(int y);

    unsigned int get_width() const;

    void set_width(unsigned int width);

    unsigned int get_height() const;

    void set_height(unsigned int height);

    Rectangle operator +(const Point& p) const;

    Rectangle operator -(const Point& p) const;

    Rectangle operator &(const Rectangle& other) const;

    Rectangle operator |(const Rectangle& other) const;
};

#endif 
