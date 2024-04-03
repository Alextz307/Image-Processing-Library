#include "brightness_and_contrast.h"

BrightnessAndContrast::BrightnessAndContrast() {
    this->alpha = 1;
    this->beta = 0;
}

BrightnessAndContrast::BrightnessAndContrast(double alpha, double beta) {
    this->alpha = alpha;
    this->beta = beta;
}
 
void BrightnessAndContrast::process(const Image& src, Image& dst) {
    dst = src * this->alpha + Image::ones(src.get_width(), src.get_height()) * this->beta;
}