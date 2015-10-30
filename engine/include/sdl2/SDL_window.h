//
// Created by Maddog on 10/4/2015.
//

#ifndef ENGINE_SDL2_SDLWINDOW
#define ENGINE_SDL2_SDLWINDOW

#include <SDL.h>
#include <memory>

namespace engine {
namespace sdl2 {

class SDL_window {

public:
    SDL_window();
    virtual ~SDL_window();

    SDL_Window* get() const;
    void reset(SDL_Window* window);
    void create();
    SDL_GLContext create_GL_context() const;

    SDL_window(const SDL_window&) = delete;
    SDL_window& operator=(const SDL_window&) = delete;

    SDL_window(SDL_window&&);
    SDL_window& operator=(SDL_window&&);


private:
    SDL_Window* window_handle;
};

struct SDL_window_deleter {
  auto operator()(SDL_window* window) -> void
  {
      if (window->get() != nullptr) {
          SDL_DestroyWindow(window->get());
      }
  }
};

using sdl_window_handle = std::unique_ptr<SDL_window, SDL_window_deleter>;

}
}

#endif