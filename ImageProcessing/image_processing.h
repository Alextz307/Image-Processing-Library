#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include "../Image/image.h"

class ImageProcessing {
    public:
        virtual void process(const Image& src, Image& dst) = 0;
};

#endif