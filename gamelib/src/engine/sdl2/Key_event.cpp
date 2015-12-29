//
// Created by alex on 7/5/15.
//

#include "sdl2/Key_event.h"

using namespace engine::sdl2;

auto Key_event::last_key_pressed() const -> Keycode
{
    return last_key_pressed_;
}

auto Key_event::last_key_released() const -> Keycode
{
    return last_key_released_;
}

auto Key_event::key_pressed(SDL_Keycode sdl_keycode) -> void
{
    key_pressed(from_sdl_keycode(sdl_keycode));
}

auto Key_event::key_pressed(Keycode key) -> void
{
    last_key_pressed_ = key;
}

auto Key_event::key_released(SDL_Keycode sdl_keycode) -> void
{
    key_released(from_sdl_keycode(sdl_keycode));
}

auto Key_event::key_released(Keycode key) -> void
{
    last_key_released_ = key;
}

auto Key_event::operator==(const Keycode& code) const -> bool
{
    return code == last_key_pressed();
}