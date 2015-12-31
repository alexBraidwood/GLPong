//
// Created by Maddog on 12/28/2015.
//

#ifndef GAMELIB_COLLIDER_H
#define GAMELIB_COLLIDER_H

namespace engine {
namespace physics2d {

class Collider {

public:
    auto is_colliding(const Collider& other) -> bool {
        return other.check_collision(*this);
    }

protected:
    virtual auto check_collision(const Collider& other) -> bool = 0;
};

}
}

#endif
