//
// Created by alex on 6/8/15.
//

#ifndef ENGINE_GAME
#define ENGINE_GAME

#include "Renderer.h"
#include <map>
#include "sdl2/SDL_window.h"
#include "sdl2/SDL_renderer.h"
#include "EventHandler.h"

namespace engine {

class Game {
public:
    Game();
    virtual ~Game() { }

public:
    void Update();
    void Init();

protected:

private:
    std::unique_ptr<sdl2::SDL_window> window;
    std::unique_ptr<sdl2::SDL_renderer> renderer;
    std::unique_ptr<Event_handler> event_handler;
    bool is_running;
};
}

#endif

