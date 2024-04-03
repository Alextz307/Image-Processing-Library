#ifndef BRIGHTNESS_AND_CONTRAST_H
#define BRIGHTNESS_AND_CONTRAST_H

#include "../image_processing.h"

class BrightnessAndContrast : public ImageProcessing { 
    private:
        double alpha;
        double beta;
    
    public:
        BrightnessAndContrast();

        BrightnessAndContrast(double alpha, double beta);

        void process(const Image& src, Image& dst) override;
};

#endif