//
// Created by Maddog on 12/8/2015.
//

#ifndef GLPONG_PADDLE_H
#define GLPONG_PADDLE_H

#include "GameObject.h"

namespace pong {
class Paddle : public engine::Game_object {
    bool is_active;
    bool is_drawn;

    bool active() const override;
    bool drawable() const override;
    void update() override;
    void draw(const engine::sdl2::SDL_renderer& renderer) override;

public:
    void activated(bool value);
    void drawable(bool value);

public:
    explicit Paddle();
    virtual ~Paddle() = default;

    Paddle(const Paddle&) = delete;
    Paddle& operator=(const Paddle&) = delete;
};
}

#endif //GLPONG_PADDLE_H
