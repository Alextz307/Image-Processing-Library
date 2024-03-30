#include "point.h"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

int Point::get_x() const {
    return this->x;
}

void Point::set_x(int x) {
    this->x = x;
}

int Point::get_y() const {
    return this->y;
}

void Point::set_y(int y) {
    this->y = y;
}
