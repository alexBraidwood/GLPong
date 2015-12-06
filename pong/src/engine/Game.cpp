//
// Created by alex on 6/8/15.
//

#include "Game.h"
#include "sdl2/SDL_window.h"

using namespace engine;
using namespace engine::sdl2;

Game::Game()
    : handler{new Event_handler}
{
    window = SDL_window::create(800, 600);
    is_running = true;
}

auto Game::Update() -> void
{
    while (is_running) {
        SDL_Event e;
        SDL_PollEvent(&e);
        handler->handle_event(e);
        if (handler->last_event() == EventType::QuitEvent
                || handler->last_key_event() == Keycode::Escape) {
            SDL_Quit();
        }
    }
}


