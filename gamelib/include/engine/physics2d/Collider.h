//
// Created by Maddog on 12/28/2015.
//

#ifndef GAMELIB_COLLIDER_H
#define GAMELIB_COLLIDER_H

#include <glm/vec3.hpp>

namespace engine {
namespace physics2d {

class Collider {

public:

    /**
     * @fn Returns whether or not two Colliders can collide
     * @returns true if able to collide, false otherwise
     */
    auto can_collide(const Collider& other) const -> bool {
        return other.check_collision(*this);
    }

    /**
     * @fn Return 2d collision point and collision tick
     * @returns GL math vector3 (x, y, t)
     */
    auto collision_point(const Collider& other) const -> const glm::vec3 {
        return other.get_collision_point(*this);
    }

protected:
    virtual auto check_collision(const Collider& other) const -> bool = 0;
    virtual auto get_collision_point(const Collider& other) const -> const glm::vec3 = 0;
};

}
}

#endif
