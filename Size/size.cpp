#include "size.h"

Size::Size() : width(0), height(0) {}

Size::Size(unsigned int width, unsigned int height) : width(width), height(height) {}

unsigned int Size::get_width() const {
    return this->width;
}

void Size::set_width(unsigned int new_width) {
    this->width = new_width;
}

unsigned int Size::get_height() const {
    return this->height;
}

void Size::set_height(unsigned int new_height) {
    this->height = new_height;
}

unsigned long long Size::get_area() const {
    return static_cast<unsigned long long>(this->width) * static_cast<unsigned long long>(this->height);
}

bool Size::operator==(const Size& other) const {
    return this->width == other.width && this->height == other.height;
}

bool Size::operator<(const Size& other) const {
    return this->get_area() < other.get_area();
}

bool Size::operator<=(const Size& other) const {
    return this->get_area() <= other.get_area();
}

bool Size::operator>(const Size& other) const {
    return this->get_area() > other.get_area();
}

bool Size::operator>=(const Size& other) const {
    return this->get_area() >= other.get_area();
}