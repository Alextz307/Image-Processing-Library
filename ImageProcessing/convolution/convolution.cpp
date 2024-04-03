#include "convolution.h"

using std::vector;

Convolution::Convolution(const vector<vector<int>>& kernel, ScalingFunction scalingFunction) {
    this->kernel = kernel;
    this->scalingFunction = scalingFunction;
}

void Convolution::process(const Image& src, Image& dst) {
    if (kernel.size() % 2 == 0 || kernel[0].size() % 2 == 0){
        throw std::invalid_argument("Kernel dimensions must be odd.");
    }

    if (dst.get_width() != src.get_width() || dst.get_height() != src.get_height()) {
        dst = Image(src.get_width(), src.get_height());
    }

    int halfKernelHeight = kernel.size() / 2;
    int halfKernelWidth = kernel[0].size() / 2;

    for (unsigned int i = halfKernelWidth; i < src.get_width() - halfKernelWidth; ++i) {
        for (unsigned int j = halfKernelHeight; j < src.get_height() - halfKernelHeight; ++j) {
            int newValue = 0;

            for (int ki = -halfKernelWidth; ki <= halfKernelWidth; ++ki) {
                for (int kj = -halfKernelHeight; kj <= halfKernelHeight; ++kj) {
                    int pixel = src.at(i + ki, j + kj);
                    int kernelValue = kernel[ki + halfKernelWidth][kj + halfKernelHeight];

                    newValue += pixel * kernelValue;
                }
            } 

            dst.set_pixel(i, j, scalingFunction(newValue));
        }
    }
}