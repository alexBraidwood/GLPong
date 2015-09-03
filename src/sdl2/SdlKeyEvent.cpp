//
// Created by alex on 7/5/15.
//

#include "SdlKeyEvent.h"
#include "Observer.h"
#include <algorithm>
#include <iostream>

using namespace engine::sdl2;

SDL_Keycode SdlKeyEvent::key_pressed() const
{
    return key_pressed_;
}

SDL_Keycode SdlKeyEvent::key_released() const
{
    return key_released_;
}

void SdlKeyEvent::key_pressed(SDL_Keycode key)
{
    key_pressed_ = key;
}

void SdlKeyEvent::key_released(SDL_Keycode key)
{
    key_released_ = key;
}