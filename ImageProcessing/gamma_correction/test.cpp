#include <iostream>
#include "gamma_correction.h"

int main() {
    Image img;
    img.load("../../assets/baboon.ascii.pgm");

    GammaCorrection processor = GammaCorrection(0.9);

    Image dst;

    processor.process(img, dst);

    dst.save("../../assets/new_processor_images/gamma_correction.ascii.pgm");

    return 0;
}