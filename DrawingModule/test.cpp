#include "drawer.h"
#include <iostream>
#include <fstream>

int main() {
    Image circle_image;
    Image line_image;
    Image rect_image1;
    Image rect_image2;

    circle_image.load("../assets/baboon.ascii.pgm");
    line_image.load("../assets/baboon.ascii.pgm");
    rect_image1.load("../assets/baboon.ascii.pgm");
    rect_image2.load("../assets/baboon.ascii.pgm");

    Drawer::drawCircle(circle_image, Point(256, 256), 64, 1);
    Drawer::drawLine(line_image, Point(20, 20), Point(256, 256), 1);
    Drawer::drawRectangle(rect_image1, Rectangle(128, 128, 100, 64), 1);
    Drawer::drawRectangle(rect_image2, Point(128, 128), Point(192, 230), 1);

    circle_image.save("../assets/new_images/new_circle_image.ascii.pgm");
    line_image.save("../assets/new_images/new_line_image.ascii.pgm");
    rect_image1.save("../assets/new_images/new_rect_image1.ascii.pgm");
    rect_image2.save("../assets/new_images/new_rect_image2.ascii.pgm");

    return 0;
}
