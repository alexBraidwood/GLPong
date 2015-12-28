//
// Created by Maddog on 11/3/2015.
//

#ifndef GLPONG_RECT_H
#define GLPONG_RECT_H


namespace engine {
namespace graphics {

struct Rect {
    Rect() : height{0}, width{0}, x{0}, y{0} {}
    Rect(float width, float height) : height{height}, width{width}, x{0}, y{0} {}
    Rect(float x, float y, float width, float height) : height{height}, width{width}, x{x}, y{y} {}
    Rect(const Rect& other)
        : height{other.height},
          width{other.width},
          x{other.x},
          y{other.y} { }

    Rect& operator=(const Rect& other)
    {
        if (&other != this) {
            this->height = other.height;
            this->width = other.width;
            this->x = other.x;
            this->y = other.y;
        }
        return *this;
    }

    float height;
    float width;
    float x;
    float y;
};
}
}


#endif //GLPONG_SQUARE_H
