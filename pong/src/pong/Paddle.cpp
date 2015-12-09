//
// Created by Maddog on 12/9/2015.
//

#include <pong/Paddle.h>
#include <iostream>

using namespace pong;

Paddle::Paddle() :
        is_active{true},
        is_drawn{true} {}

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

auto Paddle::draw() -> void
{

}

auto Paddle::update() -> void
{
    
}


