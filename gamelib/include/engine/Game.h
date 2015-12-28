//
// Created by alex on 6/8/15.
//

#ifndef ENGINE_GAME
#define ENGINE_GAME

#include <unordered_map>
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
    void add_game_object(std::unique_ptr<Game_object> object);
    void remove_game_object(const std::string tag);

    int screen_width() const;
    int screen_height() const;

protected:

private:
    std::unique_ptr<sdl2::SDL_window> window;
    std::unique_ptr<sdl2::SDL_renderer> renderer;
    std::unique_ptr<Event_handler> event_handler;
    std::unordered_map<std::string, std::unique_ptr<Game_object>> object_map;
    sdl2::Game_timer timer;

    bool is_running;
    int screen_w;
    int screen_h;
};
}

#endif

