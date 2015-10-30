//
// Created by alex on 6/8/15.
//

#ifndef ENGINE_GAME
#define ENGINE_GAME

#include "Renderer.h"
#include "Subject.h"
#include <map>
#include "sdl2/SDL_window.h"
#include "sdl2/GL_window.h"

namespace engine {

class Game {
public:
    Game();
    virtual ~Game() { }

public:
    void Update();

protected:

private:
    sdl2::sdl_window_handle window;
    sdl2::gl_window gl_window;
    bool is_running;
};
}

#endif

