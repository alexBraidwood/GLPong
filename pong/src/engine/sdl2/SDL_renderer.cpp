//
// Created by Maddog on 12/6/2015.
//


#include <sdl2/SDL_renderer.h>

using namespace engine::sdl2;

auto SDL_renderer::draw_texture(const SDL_texture& texture) -> void
{
    SDL_RenderCopy(renderer_handle, texture.get(), nullptr, nullptr);
}

auto SDL_renderer::start_render() -> void
{
    SDL_RenderClear(renderer_handle);
}

auto SDL_renderer::end_render() -> void
{
    SDL_RenderPresent(renderer_handle);
}

auto SDL_renderer::set_render_color(Uint8 r, Uint8 g, Uint8 b, Uint8 a) -> void
{
    SDL_SetRenderDrawColor(renderer_handle, r, g, b, a);
}

SDL_renderer::SDL_renderer(SDL_Renderer* handle)
        : renderer_handle{handle} {}

SDL_renderer::~SDL_renderer()
{
    if (renderer_handle != nullptr) {
        SDL_DestroyRenderer(renderer_handle);
    }
}

auto SDL_renderer::get() const -> SDL_Renderer*
{
    return renderer_handle;
}

auto SDL_renderer::reset(SDL_Renderer* renderer) -> void
{
    renderer_handle = renderer;
}

SDL_renderer::SDL_renderer(SDL_renderer&& renderer)
{
    if (this != &renderer) {
        this->renderer_handle = renderer.get();
        renderer.reset(nullptr);
    }
}

auto SDL_renderer::operator=(SDL_renderer&& renderer) -> SDL_renderer&
{
    if (this != &renderer) {
        this->renderer_handle = renderer.get();
        renderer.reset(nullptr);
    }
    return *this;
}