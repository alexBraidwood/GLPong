//
// Created by Maddog on 12/9/2015.
//

#include <Paddle.h>
#include <iostream>
#include <engine/EventHandler.h>

using namespace pong;
using namespace engine::graphics;

Paddle::Paddle(const std::string& tag, const Rect& paddle_rect) :
        Game_object(tag),
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

auto Paddle::init() const -> void
{

}

auto Paddle::draw(const engine::sdl2::SDL_renderer& renderer) -> void
{
    renderer.set_render_color(engine::graphics::Color::white());
    renderer.draw_rect(paddle_rect);
}

auto Paddle::update(const engine::Event_handler& event, float deltaTime) -> void
{
    if (event.last_event() == engine::sdl2::EventType::KeyPressedEvent) {
        if (event.last_key_event() == engine::sdl2::Keycode::Up) {
            paddle_rect.y += deltaTime * -300;
        }
        if (event.last_key_event() == engine::sdl2::Keycode::Down) {
            paddle_rect.y += deltaTime * 300;
        }
    }
}


