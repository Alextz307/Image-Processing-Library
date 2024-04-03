#include <iostream>
#include <fstream>
#include "brightness_and_contrast.h"

int main() {
    Image img;
    img.load("../../assets/baboon.ascii.pgm");

    BrightnessAndContrast processor = BrightnessAndContrast(1.5, 1.25);

    Image dst;

    processor.process(img, dst);

    dst.save("../../assets/new_processor_images/brightness_and_contrast.ascii.pgm");

    return 0;
}