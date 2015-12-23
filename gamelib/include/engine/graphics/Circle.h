//
// Created by batty-alex on 12/15/15.
//

#ifndef GLPONG_CIRCLE_H
#define GLPONG_CIRCLE_H

namespace engine {
namespace graphics {

struct Circle {

    Circle(float x, float y, float radius)
        : x(x), y(y), radius(radius) { }

    float x;
    float y;
    float radius;
};

}
}

#endif //GLPONG_CIRCLE_H
