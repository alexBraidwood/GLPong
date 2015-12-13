//
// Created by Maddog on 12/8/2015.
//

#ifndef GLPONG_GAMEOBJECT_H
#define GLPONG_GAMEOBJECT_H

#include <sdl2/SDL_renderer.h>
#include <engine/EventHandler.h>

namespace engine {

/**
 * /class Game_object template
 * /brief For use by game update loop, template is mostly redundant at this point
 * /remarks Derived needs to implement draw(), drawable(), update(), and active()
 * /a TODO(Alex): Get delta_time set up and pass with update()
 */
class Game_object {

public:
    auto do_update(const engine::Event_handler& handler, int deltaTime) -> void
    {
        if (active()) {
            update(handler, deltaTime);
        }
    }

    auto do_draw(const sdl2::SDL_renderer& renderer) -> void
    {
        if (drawable()) {
            draw(renderer);
        }
    }

protected:
    virtual auto drawable() const -> bool = 0;
    virtual auto active() const -> bool = 0;
    virtual auto draw(const sdl2::SDL_renderer& renderer) -> void = 0;
    virtual auto update(const engine::Event_handler& event, int deltaTime) -> void = 0;
};

}

#endif //GLPONG_GAMEOBJECT_H
