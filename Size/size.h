class Size {
    private:
        unsigned int width;
        unsigned int height;

    public:
        Size();

        Size(unsigned int width, unsigned int height);

        unsigned int get_width() const;

        void set_width(unsigned int new_width);

        unsigned int get_height() const;

        void set_height(unsigned int new_height);

        unsigned long long get_area() const;

        bool operator ==(const Size& other) const;

        bool operator <(const Size& other) const;

        bool operator <=(const Size& other) const;

        bool operator >(const Size& other) const;

        bool operator >=(const Size& other) const; 
};