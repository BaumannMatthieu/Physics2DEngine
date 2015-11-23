#ifndef __COLOR_H_
#define __COLOR_H_

class Color {
    public:
        Color() {

        }
        Color(const Color& color) {
            this->r = color.r;
            this->g = color.g;
            this->b = color.b;
        }
        Color(const float r, const float g, const float b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }
        virtual ~Color() {

        }
    public:
        float r, g, b;
};

#endif
