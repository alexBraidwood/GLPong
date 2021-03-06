//
// Created by batty-alex on 12/21/15.
//

#include <Ball.h>

using namespace engine::graphics;
using namespace engine::sdl2;
using namespace pong;

Ball::Ball(const std::string& tag, const engine::graphics::Circle& ballCircle)
        :Game_object{tag},
         sourceCircle{ballCircle.x, ballCircle.y, ballCircle.radius},
         velocity{0.f, 0.f}
{
}

auto Ball::active() const -> bool
{
    return true;
}

auto Ball::drawable() const -> bool
{
    return true;
}

auto Ball::draw(const engine::sdl2::SDL_renderer& renderer) -> void
{
    renderer.draw_circle(sourceCircle);
}

auto Ball::update(const engine::Event_handler& event, float deltaTime) -> void
{
    this->sourceCircle.x += velocity.x;
    this->sourceCircle.y += velocity.y;
}

auto Ball::add_velocity(glm::vec2 velocity) -> void
{
    this->velocity += velocity;
}

auto Ball::get_velocity() const -> const glm::vec2&
{
    return this->velocity;
}