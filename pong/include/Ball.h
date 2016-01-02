//
// Created by Maddog on 12/16/2015.
//

#ifndef GLPONG_BALL_H
#define GLPONG_BALL_H

#include <engine/graphics/Circle.h>
#include <engine/GameObject.h>
#include <glm/vec2.hpp>

namespace pong {
class Ball : public engine::Game_object {

    bool drawable() const override;

    bool active() const override;

    void init() const override {};

    void draw(const engine::sdl2::SDL_renderer& renderer) override;

    void update(const engine::Event_handler& event, float deltaTime) override;

public:
    explicit Ball(const std::string& tag, const engine::graphics::Circle& ballCircle);

    void add_velocity(glm::vec2 velocity);

    const glm::vec2& get_velocity() const;
private:
    engine::graphics::Circle sourceCircle;
    glm::vec2 velocity;

};
}


#endif //GLPONG_BALL_H
