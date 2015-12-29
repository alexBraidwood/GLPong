//
// Created by alex on 7/5/15.
//

#ifndef ENGINE_SDL2_SDLKEYEVENT
#define ENGINE_SDL2_SDLKEYEVENT

#include <engine/sdl2/Keycode.h>

namespace engine {
namespace sdl2 {
class Key_event {
public:
    Keycode last_key_pressed() const;
    Keycode last_key_released() const;

    void key_pressed(SDL_Keycode sdl_keycode);
    void key_pressed(Keycode key);
    void key_released(SDL_Keycode sdl_keycode);
    void key_released(Keycode key);

    bool operator==(const Keycode& code) const;

private:
    Keycode last_key_pressed_;
    Keycode last_key_released_;
};
}
}
#endif