//
// Created by alex on 7/5/15.
//

#pragma once

#include "Subject.h"
#include "EventType.h"
#include <vector>

namespace engine {
namespace sdl2 {
class SdlKeyEvent {
 public:
  SDL_Keycode key_pressed() const;

  SDL_Keycode key_released() const;

  void key_pressed(SDL_Keycode key);

  void key_released(SDL_Keycode key);

 private:
  SDL_Keycode key_pressed_;
  SDL_Keycode key_released_;
};
}
}



