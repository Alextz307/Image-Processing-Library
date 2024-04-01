#include "image.h"
#include <iostream>
#include <cassert>

void test_image_creation() {
    Image img(3, 3);

    assert(img.get_width() == 3);
    assert(img.get_height() == 3);

    for (int i = 0; i < img.get_width(); ++i) {
        for (int j = 0; j < img.get_height(); ++j) {
            assert(img.at(i, j) == 0);
        }
    }
}

void test_image_operations() {
    Image img1(2, 2);
    img1.set_pixel(0, 0, 10);
    img1.set_pixel(0, 1, 20);
    img1.set_pixel(1, 0, 30);
    img1.set_pixel(1, 1, 40);

    Image img2(2, 2);
    img2.set_pixel(0, 0, 5);
    img2.set_pixel(0, 1, 15);
    img2.set_pixel(1, 0, 25);
    img2.set_pixel(1, 1, 35);

    Image sum_image = img1 + img2;
    assert(sum_image.at(0, 0) == 15);
    assert(sum_image.at(0, 1) == 35);
    assert(sum_image.at(1, 0) == 55);
    assert(sum_image.at(1, 1) == 75);

    Image diff_image = img1 - img2;
    assert(diff_image.at(0, 0) == 5);
    assert(diff_image.at(0, 1) == 5);
    assert(diff_image.at(1, 0) == 5);
    assert(diff_image.at(1, 1) == 5);

    Image scaled_image = img1 * 1.5;
    assert(scaled_image.at(0, 0) == 15);
    assert(scaled_image.at(0, 1) == 30);
    assert(scaled_image.at(1, 0) == 45);
    assert(scaled_image.at(1, 1) == 60);
}

void test_image_io_operations() {
    Image img(2, 2);
    img.set_pixel(0, 0, 10);
    img.set_pixel(0, 1, 20);
    img.set_pixel(1, 0, 30);
    img.set_pixel(1, 1, 40);

    std::string filename = "test_image.pgm";

    assert(img.save(filename));

    Image loaded_img;
    assert(loaded_img.load(filename));

    assert(img.get_width() == loaded_img.get_width());
    assert(img.get_height() == loaded_img.get_height());

    for (int i = 0; i < img.get_width(); ++i) {
        for (int j = 0; j < img.get_height(); ++j) {
            assert(img.at(i, j) == loaded_img.at(i, j));
        }
    }
}

void test_roi_operations() {
    Image img(4, 4);

    for (int i = 0; i < img.get_width(); ++i) {
        for (int j = 0; j < img.get_height(); ++j) {
            img.set_pixel(i, j, i + j);
        }
    }

    Image roi_img(2, 2);
    assert(img.get_roi(roi_img, 1, 1, 2, 2));

    assert(roi_img.get_width() == 2);
    assert(roi_img.get_height() == 2);
    assert(roi_img.at(0, 0) == 2);
    assert(roi_img.at(0, 1) == 3);
    assert(roi_img.at(1, 0) == 3);
    assert(roi_img.at(1, 1) == 4);
}

void test_image_load_save() {
    Image image(3, 3);

    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 3; ++j) {
            image.set_pixel(i, j, i * 10 + j);
        }
    }
    
    std::cout << "Saving image...\n";
    if (image.save("test_image.pgm")) {
        std::cout << "Image saved successfully!\n";
    } else {
        std::cerr << "Failed to save image!\n";
        return;
    }
    
    Image loaded_image;
    std::cout << "Loading image...\n";
    if (loaded_image.load("test_image.pgm")) {
        std::cout << "Image loaded successfully!\n";
    } else {
        std::cerr << "Failed to load image!\n";
        return;
    }
    
    std::cout << "Loaded image:\n";
    std::cout << loaded_image << std::endl;
}

void test_image_roi() {
    Image image(5, 5);

    for (unsigned int i = 0; i < 5; ++i) {
        for (unsigned int j = 0; j < 5; ++j) {
            image.set_pixel(i, j, i + j);
        }
    }

    Rectangle roi_rect(1, 1, 3, 3);

    Image roi_image(3, 3);
    if (image.get_roi(roi_image, roi_rect)) {
        std::cout << "Region of Interest Image:\n";
        std::cout << roi_image << std::endl;
    } else {
        std::cerr << "Failed to get region of interest!\n";
    }
}

int main() {
    test_image_creation();
    test_image_io_operations();
    test_roi_operations();

    test_image_load_save();
    test_image_roi();

    std::cout << "Tests ran successfully!\n";

    return 0;
}
