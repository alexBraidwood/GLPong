//
// Created by alz12_000 on 6/30/2015.
//

#pragma once

#include <memory>
#include <SDL.h>
#include <SDL_opengl.h>
#include "SdlKeyEvent.h"

namespace engine {
  namespace sdl2 {
    class GLWindow {
     public:
      GLWindow();
      SDL_GLContext sdl_gl_context();
      void Update();

      std::shared_ptr<SdlKeyEvent> key_event_listener();

     protected:
      virtual ~GLWindow();

     private:
      std::unique_ptr<SDLWindow> sdl_window_;
      // TODO(): Wrap me up in a data structure, I'm a void pointer on the inside!
      SDL_GLContext sdl_gl_context_;
      bool loaded_successfully_;

      std::shared_ptr<SdlKeyEvent> key_event_listener_;
    };
  }
}

