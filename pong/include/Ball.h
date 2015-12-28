//
// Created by Maddog on 12/16/2015.
//

#ifndef GLPONG_BALL_H
#define GLPONG_BALL_H

#include <engine/graphics/Circle.h>
#include <engine/GameObject.h>

namespace pong {
class Ball : public engine::Game_object {

  bool drawable() const override;
  bool active() const override;
  void draw(const engine::sdl2::SDL_renderer& renderer) override;
  void update(const engine::Event_handler& event, float deltaTime) override;

 public:
  explicit Ball(const std::string& tag, const engine::graphics::Circle& ballCircle);

 private:
  engine::graphics::Circle sourceCircle;

};
}


#endif //GLPONG_BALL_H
