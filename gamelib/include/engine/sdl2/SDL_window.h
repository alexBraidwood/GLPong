//
// Created by Maddog on 10/4/2015.
//

#ifndef ENGINE_SDL2_SDLWINDOW
#define ENGINE_SDL2_SDLWINDOW

#include <memory>

struct SDL_Window;

namespace engine {
namespace sdl2 {

class SDL_window {

public:
    SDL_window(SDL_Window* handle);
    virtual ~SDL_window();

    SDL_Window* get() const;
    void reset(SDL_Window* window);
    SDL_GLContext create_GL_context() const;

    SDL_window(const SDL_window&) = delete;
    SDL_window& operator=(const SDL_window&) = delete;

    SDL_window(SDL_window&&);
    SDL_window& operator=(SDL_window&&);

    static std::unique_ptr<SDL_window> create(int height, int width);
private:
    SDL_Window* window_handle;
};

}
}

#endif