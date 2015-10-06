//
// Created by alex on 6/8/15.
//

#ifndef ENGINE_GAME
#define ENGINE_GAME

#include "Renderer.h"
#include "sdl2/GLWindow.h"
#include "Subject.h"
#include <map>
#include "sdl2/SDLWindow.h"

namespace engine {

class sdl2::SDLWindow;

class Game {
 public:
  Game();
  virtual ~Game() {}

 public:
  void Update();

 protected:

 private:
  std::unique_ptr<sdl2::SDLWindow> window_;
  std::unique_ptr<sdl2::GLWindow> gl_window_;
  bool is_running;
};
}

#endif

