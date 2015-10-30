//
// Created by alex on 6/8/15.
//

#include "Game.h"
#include "sdl2/SDL_window.h"

using namespace engine;
using namespace engine::sdl2;

Game::Game()
        : window{new SDL_window}
{
    window->create();
    gl_window = std::move(std::unique_ptr<GL_window, GL_window_deleter>(new GL_window{std::move(window)}));
    is_running = true;
}

auto Game::Update() -> void
{
    while (is_running) {
        gl_window->update();
        if (gl_window->last_key_pressed() == Keycode::Escape) {
            is_running = false;
        }
    }
}


