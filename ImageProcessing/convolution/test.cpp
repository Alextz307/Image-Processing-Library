#include "convolution.h"

using std::vector;

int main() {
    Image img;
    img.load("../../assets/baboon.ascii.pgm");

    vector<vector<int>> horizontalKernel = {
        {1, 2, 1}, 
        {0, 0, 0}, 
        {-1, -2, -1}
    };

    vector<vector<int>> verticalKernel = {
        {-1, 0, 1}, 
        {-2, 0, 2}, 
        {-1, 0, 1}
    };

    Convolution horizProcessor = Convolution(horizontalKernel, Convolution::clip);
    Convolution verticalProcessor = Convolution(verticalKernel, Convolution::clip);

    Image horiz_img;
    Image vertical_img;

    horizProcessor.process(img, horiz_img);
    verticalProcessor.process(img, vertical_img);

    horiz_img.save("../../assets/processor_images/horizontal_convolution.ascii.pgm");
    vertical_img.save("../../assets/processor_images/vertical_convolution.ascii.pgm");

    return 0;   
}