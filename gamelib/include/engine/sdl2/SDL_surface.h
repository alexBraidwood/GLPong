//
// Created by Maddog on 12/6/2015.
//

#ifndef GLPONG_SDL_SURFACE_H
#define GLPONG_SDL_SURFACE_H

struct SDL_Surface;

namespace engine {
namespace sdl2 {
class SDL_surface {
    SDL_Surface* surface_handle;

    // RAII and initialization code
public:
    SDL_surface(SDL_Surface* handle);
    virtual ~SDL_surface();

    SDL_Surface* get() const;
    void reset(SDL_Surface* surface);

    SDL_surface(const SDL_surface&) = delete;
    SDL_surface& operator=(const SDL_surface&) = delete;

    SDL_surface(SDL_surface&&);
    SDL_surface& operator=(SDL_surface&&);
};
}
}

#endif //GLPONG_SDL_SURFACE_H
