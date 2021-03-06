//
// Created by Maddog on 12/8/2015.
//

#ifndef GLPONG_PADDLE_H
#define GLPONG_PADDLE_H

#include <engine/GameObject.h>
#include <engine/graphics/Rect.h>
#include <string>

namespace pong {
class Paddle : public engine::Game_object {
    bool is_active;
    bool is_drawn;
    engine::graphics::Rect paddle_rect;

    bool active() const override;
    bool drawable() const override;
    void init() const override;
    void update(const engine::Event_handler& event, float deltaTime) override;
    void draw(const engine::sdl2::SDL_renderer& renderer) override;

public:
    void activated(bool value);
    void drawable(bool value);

public:
    explicit Paddle(const std::string& tag, const engine::graphics::Rect& paddle_rect);
    virtual ~Paddle() = default;

    Paddle(const Paddle&) = delete;
    Paddle& operator=(const Paddle&) = delete;
};
}

#endif //GLPONG_PADDLE_H
