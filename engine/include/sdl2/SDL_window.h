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
    void create();
    SDL_GLContext CreateGLContext() const;

    SDL_window(const SDL_window&) = delete;
    SDL_window(SDL_window&&) = delete;
    SDL_window& operator=(const SDL_window&) = delete;
    SDL_window& operator=(SDL_window&&) = delete;


private:
    SDL_Window* window_handle_;
};

struct SDL_window_deleter {
  auto operator()(SDL_Window* window) -> void
  {
      SDL_DestroyWindow(window);
  }
};

using sdl_window = std::unique_ptr<SDL_window, SDL_window_deleter>;

}
}

#endif