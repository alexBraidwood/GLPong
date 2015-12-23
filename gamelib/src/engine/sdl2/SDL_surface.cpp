//
// Created by batty-alex on 12/6/15.
//

#include <sdl2/SDL_surface.h>

using namespace engine::sdl2;

SDL_surface::SDL_surface(SDL_Surface* handle)
        : surface_handle{handle} {}

SDL_surface::~SDL_surface()
{
    if (surface_handle != nullptr) {
        SDL_FreeSurface(surface_handle);
    }
}

auto SDL_surface::get() const -> SDL_Surface*
{
    return surface_handle;
}

auto SDL_surface::reset(SDL_Surface* surface) -> void
{
    surface_handle = surface;
}

SDL_surface::SDL_surface(SDL_surface&& surface)
{
    if (this != &surface) {
        this->surface_handle = surface.get();
        surface.reset(nullptr);
    }
}

auto SDL_surface::operator=(SDL_surface&& surface) -> SDL_surface&
{
    if (this != &surface) {
        this->surface_handle = surface.get();
        surface.reset(nullptr);
    }
    return *this;
}