//
// Created by alex on 6/8/15.
//

#pragma once

#include "Renderer.h"
#include "GLWindow.h"
#include "ListenerType.h"
#include "Subject.h"
#include "SdlKeyEvent.h"
#include <map>

namespace engine {

class Game {
 public:
  Game();

 protected:
  virtual ~Game() {}

 public:
  void Update();

 protected:
  virtual void Initialize();
  virtual void LoadContent();

  virtual bool BeginDraw();
  virtual void Draw();
  virtual void EndDraw();

  virtual void BeginRun();
  virtual void EndRun();

 private:
  std::shared_ptr<Renderer> renderer_;
  std::unique_ptr<engine::sdl2::GLWindow> window_;

  std::unique_ptr<Subject<sdl2::SdlKeyEvent>> key_subscriber_;
  bool is_running;
};
}

