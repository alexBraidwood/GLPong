//
// Created by batty-alex on 12/21/15.
//

#include <pong/Ball.h>

using namespace engine::graphics;
using namespace engine::sdl2;
using namespace pong;

Ball::Ball(const engine::graphics::Circle& ballCircle)
  : sourceCircle{ballCircle.x, ballCircle.y, ballCircle.radius}
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

auto Ball::draw(const engine::sdl2::SDL_renderer &renderer) -> void
{
  
}

auto Ball::update(const engine::Event_handler &event, float deltaTime) -> void
{

}