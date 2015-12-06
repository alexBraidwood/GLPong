//
// Created by alex on 6/8/15.
//

#ifndef ENGINE_GAME
#define ENGINE_GAME

#include "Renderer.h"
#include <map>
#include "sdl2/SDL_window.h"
#include "sdl2/GL_window.h"
#include "Eventhandler.h"

namespace engine {

class Game {
public:
    Game();
    virtual ~Game() { }

public:
    void Update();

protected:

private:
    std::unique_ptr<sdl2::SDL_window> window;
    std::unique_ptr<Event_handler> handler;
    bool is_running;
};
}

#endif

