//
// Created by alex on 7/5/15.
//

#include "sdl2/SdlKeyEvent.h"

using namespace engine::sdl2;

auto SdlKeyEvent::last_key_pressed() const -> Keycode
{
    return last_key_pressed_;
}

auto SdlKeyEvent::last_key_released() const -> Keycode
{
    return last_key_released_;
}

auto SdlKeyEvent::key_pressed(SDL_Keycode sdl_keycode) -> void
{
    key_pressed(from_sdl_keycode(sdl_keycode));
}

auto SdlKeyEvent::key_pressed(Keycode key) -> void
{
    last_key_pressed_ = key;
}

auto SdlKeyEvent::key_released(SDL_Keycode sdl_keycode) -> void
{
    key_released(from_sdl_keycode(sdl_keycode));
}

auto SdlKeyEvent::key_released(Keycode key) -> void
{
    last_key_released_ = key;
}

auto SdlKeyEvent::operator==(const Keycode& code) const -> bool
{
    return code == last_key_pressed();
}