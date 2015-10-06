//
// Created by alz12_000 on 6/30/2015.
//

#ifndef ENGINE_SDL2_GLWINDOW
#define ENGINE_SDL2_GLWINDOW

#include "SdlKeyEvent.h"
#include "SDLWindow.h"
#include "Renderer.h"
#include "Keycode.h"

#include <memory>
#include <SDL.h>
#include <SDL_opengl.h>

namespace engine {
  namespace sdl2 {
    class GLWindow {
     public:
      GLWindow(std::unique_ptr<SDLWindow> window);
      void Update();
      virtual ~GLWindow();

      Keycode LastKeyPress() const;

     private:
      // TODO(): Wrap me up in a data structure, I'm a void pointer on the inside!
      SDL_GLContext sdl_gl_context_;
      bool loaded_successfully_;

      std::shared_ptr<SdlKeyEvent> key_event_listener_;
      std::unique_ptr<SDLWindow> window_;
      std::unique_ptr<Renderer> renderer_;
    };
  }
}

#endif
