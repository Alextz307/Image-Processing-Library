#ifndef GAMMA_CORRECTION_H
#define GAMMA_CORRECTION_H

#include "../image_processing.h"

class GammaCorrection : public ImageProcessing {
    private:
        double gamma;

    public:
        GammaCorrection();

        GammaCorrection(double gamma);

        void process(const Image& src, Image& dst) override;
};

#endif