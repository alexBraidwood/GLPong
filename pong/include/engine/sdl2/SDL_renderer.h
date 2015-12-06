//
// Created by Maddog on 12/6/2015.
//

#ifndef GLPONG_SDL_RENDERER_H
#define GLPONG_SDL_RENDERER_H

#include <sdl.h>
#include "SDL_texture.h"

namespace engine {
namespace sdl2 {
class SDL_renderer {
    SDL_Renderer* renderer_handle;

    // Drawing code
public:
    void set_render_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255);
    void start_render();
    void end_render();
    void draw_texture(const SDL_texture& texture);

    // RAII and resource management - initialization
public:
    SDL_renderer(SDL_Renderer* handle);
    virtual ~SDL_renderer();

    SDL_Renderer* get() const;
    void reset(SDL_Renderer* renderer);

    SDL_renderer(const SDL_renderer&) = delete;
    SDL_renderer& operator=(const SDL_renderer&) = delete;

    SDL_renderer(SDL_renderer&&);
    SDL_renderer& operator=(SDL_renderer&&);
};
}
}

#endif //GLPONG_SDL_RENDERER_H
