//
// Created by Maddog on 12/9/2015.
//

#include <pong/Paddle.h>
#include <iostream>
#include <pong/include/engine/EventHandler.h>

using namespace pong;
using namespace engine::graphics;

Paddle::Paddle(const Rect& paddle_rect) :
        is_active{true},
        is_drawn{true},
        paddle_rect{paddle_rect} {}

auto Paddle::active() const -> bool
{
    return is_active;
}

auto Paddle::drawable() const -> bool
{
    return is_drawn;
}

auto Paddle::activated(bool value) -> void
{
    is_active = value;
}

auto Paddle::drawable(bool value) -> void
{
    is_drawn = value;
}

auto Paddle::draw(const engine::sdl2::SDL_renderer& renderer) -> void
{
    renderer.set_render_color(engine::graphics::Color::white());
    renderer.draw_rect(paddle_rect);
}

auto Paddle::update(const engine::Event_handler& event, int deltaTime) -> void
{
    if (event.last_event() == engine::sdl2::EventType::KeyPressedEvent) {
        if (event.last_key_event() == engine::sdl2::Keycode::Up) {
            paddle_rect.y = paddle_rect.y += deltaTime*((paddle_rect.y - 1) - paddle_rect.y);
        }
        if (event.last_key_event() == engine::sdl2::Keycode::Down) {
            paddle_rect.y = paddle_rect.y += deltaTime*((paddle_rect.y + 1) - paddle_rect.y);
        }
    }
}


