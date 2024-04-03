#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include "../Size/size.h"
#include "../Point/point.h"
#include "../Rectangle/rectangle.h"

class Image {
    private:
        unsigned char** m_data;
        unsigned int m_width;
        unsigned int m_height;

    public:
        Image();

        Image(unsigned int w, unsigned int h);

        Image(const Image &other);

        Image& operator =(const Image &other);

        ~Image();

        bool load(std::string imagePath);

        bool save(std::string imagePath) const;

        Image operator +(const Image &other) const;

        Image operator -(const Image &other) const;

        Image operator *(double s) const;

        bool get_roi(Image &roiImg, Rectangle roiRect);

        bool get_roi(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height);

        bool is_empty() const;

        Size size() const;

        unsigned int get_width() const;

        unsigned int get_height() const;

        unsigned char& at(unsigned int x, unsigned int y) const;

        unsigned char& at(Point pt) const;

        void set_pixel(unsigned int x, unsigned int y, unsigned char new_value);

        void set_pixel(Point pt, unsigned char new_value);

        unsigned char* row(int x) const;

        void release();

        friend std::ostream& operator<<(std::ostream& os, const Image& dt);

        friend std::istream& operator>>(std::istream& is, Image& dt);

        static Image zeros(unsigned int width, unsigned int height);

        static Image ones(unsigned int width, unsigned int height);
};

#endif