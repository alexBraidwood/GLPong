//
// Created by alex on 6/8/15.
//

#ifndef ENGINE_GAME
#define ENGINE_GAME

#include <map>
#include <vector>

#include "GameObjectBase.h"
#include "Renderer.h"
#include "sdl2/SDL_window.h"
#include "sdl2/SDL_renderer.h"
#include "EventHandler.h"

namespace engine {

template <typename T>
class Game_object;

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
    std::vector<std::unique_ptr<Game_object_base>> game_objects;
    bool is_running;
};
}

#endif

