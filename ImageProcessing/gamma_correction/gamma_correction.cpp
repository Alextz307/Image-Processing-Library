#include "gamma_correction.h"
#include <math.h>
#include <iostream>

GammaCorrection::GammaCorrection() {
    this->gamma = 1;
}

GammaCorrection::GammaCorrection(double gamma) {
    this->gamma = gamma;
}

void GammaCorrection::process(const Image& src, Image& dst) {
    if (dst.get_width() != src.get_width() || dst.get_height() != src.get_height()) {
        dst = Image(src.get_width(), src.get_height());
    }

    for (int i = 0; i < src.get_width(); ++i) {
        for (int j = 0; j < src.get_height(); ++j) {
            dst.set_pixel(i, j, static_cast<unsigned char>(std::min((int)pow(src.at(i, j), this->gamma), 255)));
        }   
    }
}