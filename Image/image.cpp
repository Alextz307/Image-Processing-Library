#include "image.h"
#include <fstream>

Image::Image() : m_data(nullptr), m_width(0), m_height(0) {}

Image::Image(unsigned int width, unsigned int height) : m_width(width), m_height(height) {
    m_data = new unsigned char*[width];

    for (unsigned int i = 0; i < width; ++i) {
        m_data[i] = new unsigned char[height];

        for (unsigned int j = 0; j < height; ++j) {
            m_data[i][j] = 0;
        }
    }
}

Image::Image(const Image &other) : m_width(other.m_width), m_height(other.m_height) {
    m_data = new unsigned char*[m_width];

    for (unsigned int i = 0; i < m_width; ++i) {
        m_data[i] = new unsigned char[m_height];

        for (unsigned int j = 0; j < m_height; ++j) {
            m_data[i][j] = other.m_data[i][j];
        }
    }
}

Image& Image::operator =(const Image &other) {
    if (this != &other) {
        release();

        m_width = other.m_width;
        m_height = other.m_height;

        m_data = new unsigned char*[m_width];

        for (unsigned int i = 0; i < m_width; ++i) {
            m_data[i] = new unsigned char[m_height];

            for (unsigned int j = 0; j < m_height; ++j) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
    }

    return *this;
}   

Image::~Image() {
    release();
}

bool Image::load(std::string imagePath) {
    std::ifstream file(imagePath);

    if (!file.is_open()) {
        return false; 
    }

    if (!(file >> *this)) {
        return false;
    }

    file.close();

    return true;
}

bool Image::save(std::string imagePath) const {
    std::ofstream file(imagePath);

    if (!file.is_open()) {
        return false; 
    }

    file << *this;

    file.close();

    return true;
}

Image Image::operator +(const Image &other) const {
    if (this->m_width != other.get_width() || this->m_height != other.get_height()) {
        throw std::invalid_argument("Images do not have the same resolution");
    }

    Image new_image = Image(m_width, m_height);

    for (unsigned int i = 0; i < m_width; ++i) {
        for (unsigned int j = 0; j < m_height; ++j) {
            new_image.set_pixel(i, j, static_cast<unsigned char>(std::min((int)m_data[i][j] + other.at(i, j), 255)));
        }
    }

    return new_image;
}

Image Image::operator -(const Image &other) const {
    if (this->m_width != other.get_width() || this->m_height != other.get_height()) {
        throw std::invalid_argument("Images do not have the same resolution");
    }
    
    Image new_image = Image(m_width, m_height);

    for (unsigned int i = 0; i < m_width; ++i) {
        for (unsigned int j = 0; j < m_height; ++j) {
            new_image.set_pixel(i, j, static_cast<unsigned char>(std::max((int)m_data[i][j] - other.at(i, j), 0)));
        }
    }

    return new_image;
}

Image Image::operator *(double s) const {
    Image new_image = Image(m_width, m_height);

    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_height; ++j) {
            new_image.set_pixel(i, j, static_cast<unsigned char>(std::min(int(s * m_data[i][j]), 255)));
        }
    }

    return new_image;
}

bool Image::get_roi(Image &roiImg, Rectangle roiRect) {
    if (roiRect.get_x() + roiRect.get_width() > m_width) {
        return false;
    }

    if (roiRect.get_y() + roiRect.get_height() > m_height) {
        return false;
    }

    for (unsigned int i = 0; i < roiRect.get_width(); ++i) {
        for (unsigned int j = 0; j < roiRect.get_height(); ++j) {
            roiImg.set_pixel(i, j, m_data[roiRect.get_x() + i][roiRect.get_y() + j]);
        }
    }

    return true;
}

bool Image::get_roi(Image &roiImg, unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
    if (x + width > m_width) {
        return false;
    }

    if (y + height > m_height) {
        return false;
    }

    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {
            roiImg.set_pixel(i, j, m_data[x + i][y + j]);
        }
    }

    return true;
}

bool Image::is_empty() const {
    return m_data == nullptr && m_width == 0 && m_height == 0;
}

Size Image::size() const {
    return Size(m_width, m_height);
}

unsigned int Image::get_width() const {
    return m_width;
}

unsigned int Image::get_height() const {
    return m_height;
}

unsigned char& Image::at(unsigned int x, unsigned int y) const {
    return m_data[x][y];
}

unsigned char& Image::at(Point pt) const {
    return m_data[pt.get_x()][pt.get_y()];
}

void Image::set_pixel(unsigned int x, unsigned int y, unsigned char new_value) {
    m_data[x][y] = new_value;
}

void Image::set_pixel(Point pt, unsigned char new_value) {
    m_data[pt.get_x()][pt.get_y()] = new_value;
}

unsigned char* Image::row(int x) const {
    return m_data[x];
}

void Image::release() {
    if (m_data != nullptr) {
        for (unsigned int i = 0; i < m_width; ++i) {
            delete[] m_data[i];
        }

        delete[] m_data;

        m_data = nullptr;
    }
}

std::ostream& operator <<(std::ostream& os, const Image& dt) {
    os << "P2\n";
    os << "# Simple pgm image example\n";
    os << dt.get_width() << " " << dt.get_height() << "\n";
    os << "255\n";

    for (unsigned int i = 0; i < dt.get_width(); ++i) {
        for (unsigned int j = 0; j < dt.get_height(); ++j) {
            os << static_cast<unsigned int>(dt.at(i, j)) << " ";
        }

        os << "\n";
    }

    return os;
}

std::istream& operator >>(std::istream& is, Image& dt) {
    std::string magic_number;
    is >> magic_number;

    if (magic_number != "P2") {
        is.setstate(std::ios::failbit);
        return is;
    }

    char ch = is.peek();

    while (ch == '#' || ch == '\n') {
        is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ch = is.peek();
    }

    unsigned int width, height;
    is >> width >> height;
    dt = Image(width, height);

    unsigned int max_pixel_value;
    is >> max_pixel_value;

    is.ignore();

    for (unsigned int i = 0; i < width; ++i) {
        for (unsigned int j = 0; j < height; ++j) {
            unsigned int pixel_value;
            is >> pixel_value;
            dt.set_pixel(i, j, static_cast<unsigned char>(pixel_value));
        }
    }

    return is;
}

Image Image::zeros(unsigned int width, unsigned int height) {
    return Image(width, height);
}

Image Image::ones(unsigned int width, unsigned int height) {
    Image image = Image(width, height);

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            image.set_pixel(i, j, 1);
        }
    }

    return image;
}
