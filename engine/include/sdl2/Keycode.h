//
// Created by Maddog on 9/6/2015.
//

#ifndef ENGINE_SDL2_KEYCODE
#define ENGINE_SDL2_KEYCODE

#include <SDL_keycode.h>

namespace engine {
namespace sdl2 {

inline Keycode FromSdlKeycode(SDL_Keycode keycode) {
  return static_cast<Keycode>(keycode);
}

enum class Keycode {
  Unknown = SDLK_UNKNOWN,
  Return = SDLK_RETURN,
  Escape = SDLK_ESCAPE,
  Backspace = SDLK_BACKSPACE,
  Tab = SDLK_TAB,
  Space = SDLK_SPACE,
  Exclamation = SDLK_EXCLAIM,
  DoubleQuote = SDLK_QUOTEDBL,
  Hash = SDLK_HASH,
  Percent = SDLK_PERCENT,
  Dollar = SDLK_DOLLAR,
  Ampersand = SDLK_AMPERSAND,
  Quote = SDLK_QUOTE
};
}
}

#endif
