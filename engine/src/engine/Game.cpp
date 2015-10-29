//
// Created by alex on 6/8/15.
//

#include "Game.h"
#include "SDL_window.h"

using namespace engine;
using namespace engine::sdl2;

Game::Game()
        : window_(new SDL_window),
          gl_window_(new GL_window(std::move(window_)))
{

    is_running = true;
}

auto Game::Update() -> void
{
    while (is_running) {
        gl_window_->Update();
        if (gl_window_->LastKeyPress()==Keycode::Escape) {
            is_running = false;
        }
    }
}


