//
// Created by alz12_000 on 6/30/2015.
//

#include <SDL.h>
#include "sdl2/GL_window.h"

using namespace engine::sdl2;

GL_window::GL_window(std::unique_ptr<SDL_window> window_handle)
        :   window{std::move(window_handle)},
            renderer_{new Renderer},
            key_event_listener_{new SdlKeyEvent}
{
    if (window) {
        create_context();
    }
    renderer_->Init();
}

GL_window::~GL_window()
{
    if (sdl_gl_context != nullptr) {
        SDL_GL_DeleteContext(sdl_gl_context);
    }
}

auto GL_window::create_context() -> void
{
    auto glContext = SDL_GL_CreateContext(window->get());
    if (glContext == nullptr) {
        // TODO(): Handle the error here
    }
}

auto GL_window::get() const -> SDL_GLContext
{
    return sdl_gl_context;
}

auto GL_window::reset(const SDL_GLContext context) -> void
{
    sdl_gl_context = context;
}

auto GL_window::get_sdl_window() const -> SDL_window&
{
    return *window;
}

auto GL_window::update() -> void
{
    SDL_GL_SwapWindow(window->get());
    SDL_Event e;
    SDL_PollEvent(&e);
    renderer_->Update();
    switch (e.type) {
    case SDL_QUIT:
        SDL_Quit();
        key_event_listener_->key_pressed('\033'); // Escape :-)
        break;
    case SDL_KEYDOWN:
        key_event_listener_->key_pressed(e.key.keysym.sym);
        break;
    case SDL_KEYUP:
        key_event_listener_->key_released(e.key.keysym.sym);
        break;
    }
}
GL_window& GL_window::operator=(GL_window&& window)
{
    if (this != &window) {
        this->sdl_gl_context = window.get();
        this->window->reset(window.get_sdl_window().get());
        window.get_sdl_window().reset(nullptr);
        window.reset(nullptr);
    }
    return *this;
}
GL_window::GL_window(GL_window&& window)
    : sdl_gl_context{window.get()}
{
    this->window->reset(window.get_sdl_window().get());
    window.reset(nullptr);
    window.get_sdl_window().reset(nullptr);
}
