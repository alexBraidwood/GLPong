//
// Created by alz12_000 on 6/30/2015.
//

#include "sdl2/GL_window.h"

using namespace engine::sdl2;

GL_window::GL_window(sdl_window_handle window_handle)
        : window{std::move(window_handle)},
          renderer_{new Renderer},
          key_event_listener_{new SdlKeyEvent}
{
    sdl_gl_context = window->create_GL_context();
    renderer_->Init();
}

auto GL_window::get() const -> SDL_GLContext
{
    return sdl_gl_context;
}

auto GL_window::reset(const SDL_GLContext context) -> void
{
    sdl_gl_context = context;
}

auto GL_window::SDL_window() const -> sdl2::SDL_window&
{
    return *window;
}

auto GL_window::last_key_pressed() const -> Keycode
{
    return FromSdlKeycode(key_event_listener_->key_pressed());
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
        this->SDL_window().reset(window.SDL_window().get());
        window.SDL_window().reset(nullptr);
        window.reset(nullptr);
    }
    return *this;
}
GL_window::GL_window(GL_window&& window)
    : sdl_gl_context{window.get()},
      window{std::move(window.SDL_window())}
{
    window.reset(nullptr);
}
