//
// Created by Maddog on 11/3/2015.
//

#ifndef GLPONG_RECT_H
#define GLPONG_RECT_H

#include <GL/glew.h>
#include <GL/gl.h>

namespace engine {
namespace graphics {

struct Rect {
    Rect() : height{0}, width{0}, x{0}, y{0} {}
    Rect(int width, int height) : height{height}, width{width}, x{0}, y{0} {}
    Rect(int x, int y, int width, int height) : height{height}, width{width}, x{x}, y{y} {}

    int height;
    int width;
    int x;
    int y;
};
}
}


#endif //GLPONG_SQUARE_H
