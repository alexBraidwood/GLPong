//
// Created by Maddog on 12/8/2015.
//

#ifndef GLPONG_GAMEOBJECT_H
#define GLPONG_GAMEOBJECT_H

#include "GameObjectBase.h"

namespace engine {

/**
 * /class Game_object template
 * /brief For use by game update loop, CRTP calls update on derived
 * /remarks Derived needs to implement draw(), drawable(), update(), and active()
 * /a TODO(Alex): Get delta_time set up and pass with update()
 */
template<typename T>
class Game_object : public Game_object_base {

public:
    auto do_update() -> void override
    {
        if (active()) {
            update();
        }
    }

    auto do_draw() -> void override
    {
        if (drawable()) {
            draw();
        }
    }

protected:
    virtual auto drawable() const -> bool = 0;
    virtual auto active() const -> bool = 0;
    virtual auto draw() -> void = 0;
    virtual auto update() -> void = 0;
};

}

#endif //GLPONG_GAMEOBJECT_H
