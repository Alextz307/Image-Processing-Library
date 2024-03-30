#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle() : x(0), y(0), width(0), height(0) {}

Rectangle::Rectangle(int x, int y, unsigned int width, unsigned int height) : x(x), y(y), width(width), height(height) {}

int Rectangle::get_x() const {
    return this->x;
}

void Rectangle::set_x(int x) {
    this->x = x;
}

int Rectangle::get_y() const {
    return this->y;
}

void Rectangle::set_y(int y) {
    this->y = y;
}

unsigned int Rectangle::get_width() const {
    return this->width;
}

void Rectangle::set_width(unsigned int width) {
    this->width = width;
}

unsigned int Rectangle::get_height() const {
    return this->height;
}

void Rectangle::set_height(unsigned int height) {
    this->height = height;
}

Rectangle Rectangle::operator +(const Point& p) const {
    return Rectangle(x + p.get_x(), y + p.get_y(), width, height);
}

Rectangle Rectangle::operator -(const Point& p) const {
    return Rectangle(x - p.get_x(), y - p.get_y(), width, height);
}

Rectangle Rectangle::operator &(const Rectangle& other) const {
    int x1 = std::max(x, other.x);
    int y1 = std::max(y, other.y);
    int x2 = std::min(x + width, other.x + other.width);
    int y2 = std::min(y + height, other.y + other.height);

    unsigned int intersection_width = std::max(0, x2 - x1);
    unsigned int intersection_height = std::max(0, y2 - y1);

    return Rectangle(x1, y1, intersection_width, intersection_height);
}

Rectangle Rectangle::operator |(const Rectangle& other) const {
    int x1 = std::min(x, other.x);
    int y1 = std::min(y, other.y);
    int x2 = std::max(x + width, other.x + other.width);
    int y2 = std::max(y + height, other.y + other.height);

    unsigned int union_width = x2 - x1;
    unsigned int union_height = y2 - y1;

    return Rectangle(x1, y1, union_width, union_height);
}
