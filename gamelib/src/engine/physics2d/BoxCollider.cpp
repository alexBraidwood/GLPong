//
// Created by Maddog on 12/31/2015.
//

#include <physics2d/BoxCollider.h>

using namespace engine::physics2d;

auto BoxCollider::check_collision(const Collider& other) const -> bool
{
    return false;
}

auto BoxCollider::get_collision_point(const Collider& other) const -> const glm::vec3
{
    return glm::vec3(0.f, 0.f, 0.f);
}