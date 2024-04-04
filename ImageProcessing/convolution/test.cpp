#include "convolution.h"

using std::vector;

int main() {
    Image img;
    img.load("../../assets/baboon.ascii.pgm");

    vector<vector<int>> noopKernel = {
        {0, 0, 0}, 
        {0, 1, 0}, 
        {0, 0, 0}
    };

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

    Convolution noopProcessor = Convolution(noopKernel, Convolution::clip);
    Convolution horizProcessor = Convolution(horizontalKernel, Convolution::clip);
    Convolution verticalProcessor = Convolution(verticalKernel, Convolution::clip);

    Image noopImg;
    Image horizImg;    
    Image verticalImg; 

    noopProcessor.process(img, noopImg);
    horizProcessor.process(img, horizImg);
    verticalProcessor.process(img, verticalImg);

    noopImg.save("../../assets/processor_images/noop_convolution.ascii.pgm");
    horizImg.save("../../assets/processor_images/horizontal_convolution.ascii.pgm");
    verticalImg.save("../../assets/processor_images/vertical_convolution.ascii.pgm");

    return 0;   
}