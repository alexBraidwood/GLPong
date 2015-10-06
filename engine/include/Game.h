//
// Created by alex on 6/8/15.
//

#ifndef ENGINE_GAME
#define ENGINE_GAME

#include "Renderer.h"
#include "sdl2/GLWindow.h"
#include "ListenerType.h"
#include "Subject.h"
#include "SdlKeyEvent.h"
#include <map>

namespace engine {

class sdl2::SDLWindow;

class Game {
 public:
  Game();
  virtual ~Game() {}

 public:
  void Update();

 protected:
  virtual void Initialize();

 private:
  Subject<sdl2::SdlKeyEvent>* key_subscriber_;
  std::unique_ptr<sdl2::SDLWindow> window_;
  std::unique_ptr<Renderer> renderer_;
  bool is_running;
};
}

#endif

