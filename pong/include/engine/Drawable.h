//
// Created by Maddog on 12/8/2015.
//

#ifndef GLPONG_DRAWABLE_H
#define GLPONG_DRAWABLE_H

namespace engine {

/**
 * /class Drawable template
 * /brief For use by game draw loop, CRTP calls update on derived
 * /remarks Derived needs to implement bool active() and void draw()
 */
template <typename T>
class Drawable {
    auto child() const -> T&
    {
        return static_cast<T&>(*this);
    }

public:
    auto do_draw() -> void
    {
        if (child().active()) {
            child().draw();
        }
    }
};

}

#endif //GLPONG_DRAWABLE_H
