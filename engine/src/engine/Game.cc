//
// Created by alex on 6/8/15.
//

#include "Game.h"
#include <sdl2/SDLWindow.h>

using namespace engine;
using namespace engine::sdl2;

Game::Game()
  : window_(new SDLWindow),
    gl_window_(new GLWindow(std::move(window_))) {

  is_running = true;
}

void Game::Update() {
  while (is_running) {
    gl_window_->Update();
    if (gl_window_->LastKeyPress() == Keycode::Escape) {
      is_running = false;
    }
  }
}


