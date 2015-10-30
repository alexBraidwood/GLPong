//
// Created by alex on 6/8/15.
//

#include "Game.h"
#include "sdl2/SDL_window.h"

using namespace engine;
using namespace engine::sdl2;

Game::Game()
{
    auto window = SDL_window::create(800, 600);
    gl_window.reset(new GL_window(std::move(window)));
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


