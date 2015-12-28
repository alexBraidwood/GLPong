//
// Created by Maddog on 12/6/2015.
//

#ifndef GLPONG_SDL_RENDERER_H
#define GLPONG_SDL_RENDERER_H

#include "SDL_texture.h"
#include <engine/graphics/Color.h>
#include <engine/graphics/Rect.h>
#include <engine/graphics/Circle.h>

    struct SDL_Renderer;

namespace engine {
namespace sdl2 {
class SDL_renderer {
    SDL_Renderer* renderer_handle;

    // Drawing code
public:
    void set_render_color(const engine::graphics::Color& color) const;
    void clear(const engine::graphics::Color& color);
    void present();
    void draw_texture(const SDL_texture& texture) const;
    void draw_rect(const graphics::Rect& rect) const;
    void draw_circle(const graphics::Circle& circle) const;

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
