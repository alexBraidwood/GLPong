//
// Created by Maddog on 12/6/2015.
//


#include <sdl2/SDL_renderer.h>

using namespace engine::sdl2;

auto SDL_renderer::draw_rect(const graphics::Rect& rect) -> void
{
    SDL_Rect fillRect {
        rect.x, rect.y, rect.width, rect.height
    };
    SDL_RenderFillRect(renderer_handle, &fillRect);
}

auto SDL_renderer::draw_texture(const SDL_texture& texture) -> void
{
    SDL_RenderCopy(renderer_handle, texture.get(), nullptr, nullptr);
}

auto SDL_renderer::clear() -> void
{
    SDL_RenderClear(renderer_handle);
}

auto SDL_renderer::present() -> void
{
    SDL_RenderPresent(renderer_handle);
}

auto SDL_renderer::set_render_color(const engine::graphics::Color& color) -> void
{
    SDL_SetRenderDrawColor(renderer_handle, color.r, color.g, color.b, color.a);
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