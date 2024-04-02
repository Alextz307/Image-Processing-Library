#include "gamma_correction.h"
#include <math.h>

GammaCorrection::GammaCorrection() {
    this->gamma = 1;
}

GammaCorrection::GammaCorrection(double gamma) {
    this->gamma = gamma;
}

void GammaCorrection::process(const Image& src, Image& dst) {
    for (int i = 0; i < src.get_width(); ++i) {
        for (int j = 0; j < src.get_height(); ++j) {
            dst.set_pixel(i, j, static_cast<unsigned char>((src.at(i, j), gamma)));
        }   
    }
}