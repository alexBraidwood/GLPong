//
// Created by alz12_000 on 6/30/2015.
//

#ifndef ENGINE_SDL2_GLWINDOW
#define ENGINE_SDL2_GLWINDOW

#include <memory>
#include <SDL.h>
#include <SDL_opengl.h>
#include <sdl2/SDLWindow.h>
#include "SdlKeyEvent.h"

namespace engine {
  namespace sdl2 {
    class GLWindow {
     public:
      GLWindow(std::unique_ptr<SDLWindow> parent);
      SDL_GLContext sdl_gl_context();
      void Update();

      std::shared_ptr<SdlKeyEvent> key_event_listener();

     protected:
      virtual ~GLWindow();

     private:
      // TODO(): Wrap me up in a data structure, I'm a void pointer on the inside!
      SDL_GLContext sdl_gl_context_;
      bool loaded_successfully_;

      std::shared_ptr<SdlKeyEvent> key_event_listener_;
      std::unique_ptr<SDLWindow> parent_window_;
    };
  }
}

#endif
