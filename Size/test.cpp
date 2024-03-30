#include <iostream>
#include <cassert>
#include "size.h"

void test_constructor() {
    Size s1;
    assert(s1.get_width() == 0);
    assert(s1.get_height() == 0);

    Size s2(3, 4);
    assert(s2.get_width() == 3);
    assert(s2.get_height() == 4);
}

void test_width_height() {
    Size s1;
    s1.set_width(10);
    assert(s1.get_width() == 10);
    s1.set_height(20);
    assert(s1.get_height() == 20);
}

void test_area() {
    Size s1(4, 5);
    assert(s1.get_area() == 20);
}

void test_comparison_operators() {
    Size s1(4, 5);
    Size s2(3, 6);
    Size s3(4, 5);

    assert(s1 == s3);
    assert(s2 < s1);
    assert(s3 > s2);
    assert(s1 <= s3);
    assert(s3 >= s2);
}

int main() {
    test_constructor();
    test_width_height();
    test_area();
    test_comparison_operators();

    std::cout << "Tests ran successfully!\n";

    return 0;
}