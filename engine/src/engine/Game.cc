//
// Created by alex on 6/8/15.
//

#include "Game.h"
#include <sdl2/SDLWindow.h>

using namespace engine;
using namespace engine::sdl2;

Game::Game()
  : window_(new SDLWindow) {
  window_->Create();
  is_running = true;
}

void Game::Update() {
  while (is_running) {

  }
}

void Game::Initialize() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
  }
}


