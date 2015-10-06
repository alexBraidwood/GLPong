//
// Created by Maddog on 10/4/2015.
//

#ifndef ENGINE_SDL2_SDLWINDOW
#define ENGINE_SDL2_SDLWINDOW

#include <SDL.h>

namespace engine {
namespace sdl2 {
class SDLWindow {

 public:
  SDLWindow(SDL_Window* window);
  SDLWindow();
  virtual ~SDLWindow();


  operator SDL_Window*() const {
    return window_handle_;
  }
  void Create();
  SDL_GLContext CreateGLContext() const;

 private:
  SDL_Window* window_handle_;
};
}
}

#endif