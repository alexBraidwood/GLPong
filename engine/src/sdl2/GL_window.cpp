//
// Created by alz12_000 on 6/30/2015.
//

#include "sdl2/GL_window.h"

using namespace engine::sdl2;

GL_window::GL_window(sdl_window window)
        :window{std::move(window)},
         renderer_{new Renderer},
         key_event_listener_{new SdlKeyEvent}
{
    window->create();
    sdl_gl_context_ = window->CreateGLContext();
    renderer_->Init();
}

auto GL_window::get() const -> SDL_GLContext
{
    return sdl_gl_context_;
}

auto GL_window::last_key_pressed() const -> Keycode
{
    return FromSdlKeycode(key_event_listener_->key_pressed());
}

auto GL_window::update() -> void
{
    SDL_GL_SwapWindow(window_->get());
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