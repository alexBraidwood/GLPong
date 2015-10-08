//
// Created by alex on 7/5/15.
//

#include "sdl2/SdlKeyEvent.h"
#include "Observer.h"

using namespace engine::sdl2;

auto SdlKeyEvent::key_pressed() const -> SDL_Keycode {
  return key_pressed_;
}

auto SdlKeyEvent::key_released() const -> SDL_Keycode {
  return key_released_;
}

auto SdlKeyEvent::key_pressed(SDL_Keycode key) -> void {
  key_pressed_ = key;
}

auto SdlKeyEvent::key_released(SDL_Keycode key) -> void {
  key_released_ = key;
}