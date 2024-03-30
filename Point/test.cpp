#include <iostream>
#include <cassert>
#include "point.h"

void test_default_constructor() {
    Point p;
    assert(p.get_x() == 0);
    assert(p.get_y() == 0);
}

void test_parameterized_constructor() {
    Point p(3, 4);
    assert(p.get_x() == 3);
    assert(p.get_y() == 4);
}

void test_getters_setters() {
    Point p;
    p.set_x(5);
    p.set_y(7);
    assert(p.get_x() == 5);
    assert(p.get_y() == 7);
}

int main() {
    test_default_constructor();
    test_parameterized_constructor();
    test_getters_setters();
    
    std::cout << "Tests ran successfully!\n";

    return 0;
}
