//
// Created by batty-alex on 12/30/15.
//

#ifndef GAMEPROJECT_CIRCLECOLLIDER_H
#define GAMEPROJECT_CIRCLECOLLIDER_H

#include "Collider.h"
#include <engine/graphics/Circle.h>

namespace engine {
namespace physics2d {
class CircleCollider : public Collider {

    engine::graphics::Circle boundingCircle;

private:
    bool check_collision(const Collider& other) const override;
    const glm::vec3 get_collision_point(const Collider& other) const override;

};
}
}


#endif //GAMEPROJECT_CIRCLECOLLIDER_H
