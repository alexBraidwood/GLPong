//
// Created by alex on 6/8/15.
//

#ifndef ENGINE_GAME
#define ENGINE_GAME

#include <map>
#include <vector>

#include "GameObject.h"
#include "Renderer.h"
#include "sdl2/SDL_window.h"
#include "sdl2/SDL_renderer.h"
#include "GameTimer.h"
#include "EventHandler.h"

namespace engine {

class Game_object;

class Game {
public:
    Game();
    virtual ~Game() { }

public:
    void Update();
    void Init();
    const sdl2::Game_timer& game_timer() const;

protected:

private:
    std::unique_ptr<sdl2::SDL_window> window;
    std::unique_ptr<sdl2::SDL_renderer> renderer;
    std::unique_ptr<Event_handler> event_handler;
    // TODO(Encapsulation): Expose this through the public interface, AddObject(), RemoveObject()?
    std::vector<std::unique_ptr<Game_object>> game_objects;
    sdl2::Game_timer timer;

    bool is_running;
    int screen_w;
    int screen_h;
};
}

#endif

