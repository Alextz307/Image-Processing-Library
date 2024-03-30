#include "rectangle.h"
#include <cassert>
#include <iostream>

void test_constructor() {
    Rectangle r;
    assert(r.get_x() == 0);
    assert(r.get_y() == 0);
    assert(r.get_width() == 0);
    assert(r.get_height() == 0);

    Rectangle r2(1, 2, 3, 4);
    assert(r2.get_x() == 1);
    assert(r2.get_y() == 2);
    assert(r2.get_width() == 3);
    assert(r2.get_height() == 4);
}

void test_translation() {
    Rectangle r(1, 2, 3, 4);
    Point p(5, 6);

    Rectangle translated = r + p;
    assert(translated.get_x() == 6);
    assert(translated.get_y() == 8);

    Rectangle translated_back = translated - p;
    assert(translated_back.get_x() == r.get_x());
    assert(translated_back.get_y() == r.get_y());
}

void test_intersection_union() {
    Rectangle r1(1, 2, 3, 4);
    Rectangle r2(3, 4, 5, 6);

    Rectangle intersection = r1 & r2;
    assert(intersection.get_x() == 3);
    assert(intersection.get_y() == 4);
    assert(intersection.get_width() == 1);
    assert(intersection.get_height() == 2);

    Rectangle union_rect = r1 | r2;
    assert(union_rect.get_x() == 1);
    assert(union_rect.get_y() == 2);
    assert(union_rect.get_width() == 7);
    assert(union_rect.get_height() == 8);
}

int main() {
    test_constructor();
    test_translation();
    test_intersection_union();

    std::cout << "Tests ran successfully!\n";

    return 0;
}
