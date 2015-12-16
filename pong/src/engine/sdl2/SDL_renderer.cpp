//
// Created by Maddog on 12/6/2015.
//


#include <sdl2/SDL_renderer.h>

using namespace engine::sdl2;

auto SDL_renderer::draw_rect(const graphics::Rect& rect) const -> void
{
    SDL_Rect fillRect {
        int(rect.x + 0.5), int(rect.y + 0.5), int(rect.width + 0.5), int(rect.height + 0.5)
    };
    SDL_RenderFillRect(renderer_handle, &fillRect);
}

auto SDL_renderer::draw_texture(const SDL_texture& texture) const -> void
{
    SDL_RenderCopy(renderer_handle, texture.get(), nullptr, nullptr);
}

auto SDL_renderer::draw_circle(const graphics::Circle& circle) const -> void
{
    // Using Midpoint circle algorithm
    float x = circle.radius;
    float y = 0;
    float decisionOver2 = 1.0f - x;

    while (y <= x) {
        SDL_RenderDrawLine(renderer_handle, circle.x, circle.y, x + circle.x, y + circle.y);
        SDL_RenderDrawLine(renderer_handle, circle.x, circle.y, y + circle.x, x + circle.y);
        SDL_RenderDrawLine(renderer_handle, circle.x, circle.y, -x + circle.x, y + circle.y);
        SDL_RenderDrawLine(renderer_handle, circle.x, circle.y, -y + circle.x, x + circle.y);
        SDL_RenderDrawLine(renderer_handle, circle.x, circle.y, -x + circle.x, -y + circle.y);
        SDL_RenderDrawLine(renderer_handle, circle.x, circle.y, -y + circle.x, -x + circle.y);
        SDL_RenderDrawLine(renderer_handle, circle.x, circle.y, x + circle.x, -y + circle.y);
        SDL_RenderDrawLine(renderer_handle, circle.x, circle.y, y + circle.x, -x + circle.y);
        y += 0.1f;
        if (decisionOver2 <= 0) {
            decisionOver2 += 2 * y + 1;
        } else {
            x -= 0.1f;
            decisionOver2 += 2 * (y - x) + 1;
        }
    }
}

auto SDL_renderer::clear(const graphics::Color& clearColor) -> void
{
    set_render_color(clearColor);
    SDL_RenderClear(renderer_handle);
}

auto SDL_renderer::present() -> void
{
    SDL_RenderPresent(renderer_handle);
}

auto SDL_renderer::set_render_color(const engine::graphics::Color& color) const -> void
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