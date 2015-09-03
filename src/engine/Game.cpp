//
// Created by alex on 6/8/15.
//

#include "Game.h"

using namespace engine;

Game::Game() {
  window_ = std::make_unique<sdl2::GLWindow>();
  renderer_ = std::make_shared<Renderer>();

  is_running = true;
}

void Game::Update() {
  while (is_running) {
    // When do we close the window?
    // I have no idea, yet, let the renderer decide
    window_->Update();
    renderer_->Update();
    if (window_->key_event_listener()->key_pressed() == SDLK_ESCAPE) {
      is_running = false;
    }
  }
}


