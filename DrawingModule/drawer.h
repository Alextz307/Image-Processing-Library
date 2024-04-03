#ifndef DRAWER_H
#define DRAWER_H

#include "../Point/point.h"
#include "../Size/size.h"
#include "../Rectangle/rectangle.h"
#include "../Image/image.h"

class Drawer {
    private:
        static int squared(int x) {
            return x * x;
        }

        static int dist(int x1, int y1, int x2, int y2) {
            return squared(x2 - x1) + squared(y2 - y1);
        }

        static bool are_colinear(int x1, int y1, int x2, int y2, int x3, int y3) {
            return (x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1);
        }

        static bool is_inside_rectangle(int x, int y, int x1, int y1, int x2, int y2) {
            return x1 <= x && x <= x2 && y1 <= y && y <= y2;
        }

    public: 
        static void drawCircle(Image& img, Point center, int radius, unsigned char color) {
            for (int i = 0; i < img.get_width(); ++i) {
                for (int j = 0; j < img.get_height(); ++j) {
                    if (dist(center.get_x(), center.get_y(), i, j) <= squared(radius)) {
                        img.set_pixel(i, j, color);
                    }
                }
            }
        }

        static void drawLine(Image &img, Point p1, Point p2, unsigned char color) {
            for (int i = 0; i < img.get_width(); ++i) {
                for (int j = 0; j < img.get_height(); ++j) {
                    if (are_colinear(p1.get_x(), p1.get_y(), p2.get_x(), p2.get_y(), i, j)) {
                        img.set_pixel(i, j, color);
                    }
                }
            }
        }

        static void drawRectangle(Image &img, Rectangle r, unsigned char color) {
            for (int i = 0; i < img.get_width(); ++i) {
                for (int j = 0; j < img.get_height(); ++j) {
                    if (is_inside_rectangle(i, j, r.get_x(), r.get_y(), r.get_x() + r.get_width() - 1, r.get_y() + r.get_height() - 1)) {
                        img.set_pixel(i, j, color);
                    }
                }
            }
        }

        static void drawRectangle(Image &img, Point tl, Point br, unsigned char color) {
            for (int i = 0; i < img.get_width(); ++i) {
                for (int j = 0; j < img.get_height(); ++j) {
                    if (is_inside_rectangle(i, j, tl.get_x(), tl.get_y(), br.get_x(), br.get_y())) {
                        img.set_pixel(i, j, color);
                    }
                }
            }
        }
};

#endif