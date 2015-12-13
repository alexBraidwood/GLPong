//
// Created by alex on 12/12/15.
//

#ifndef GLPONG_PLAYFIELD_H
#define GLPONG_PLAYFIELD_H

#include <engine/GameObject.h>

namespace pong {
    class Play_field : public engine::Game_object {
        virtual bool drawable() const override;
        virtual bool active() const override;
        virtual void draw(const engine::sdl2::SDL_renderer& renderer) override;
        virtual void update(const engine::Event_handler& event) override;

        engine::graphics::Rect field_bounds;
    };
}

#endif //GLPONG_PLAYFIELD_H
