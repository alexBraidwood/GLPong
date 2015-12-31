//
// Created by batty-alex on 12/30/15.
//

#ifndef GAMEPROJECT_SQUARECOLLIDER_H
#define GAMEPROJECT_SQUARECOLLIDER_H

#include "Collider.h"
#include <engine/graphics/Rect.h>

namespace engine {
namespace physics2d {
class BoxCollider : Collider {

    engine::graphics::Rect boundingRect;

private:
    bool check_collision(const Collider& other) const override;
    const glm::vec3 get_collision_point(const Collider& other) const override;
};
}
}

#endif //GAMEPROJECT_SQUARECOLLIDER_H
