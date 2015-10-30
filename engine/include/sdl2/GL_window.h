//
// Created by alz12_000 on 6/30/2015.
//

#ifndef ENGINE_SDL2_GLWINDOW
#define ENGINE_SDL2_GLWINDOW

#include "SdlKeyEvent.h"
#include "sdl2/SDL_window.h"
#include "Renderer.h"
#include "Keycode.h"

#include <memory>
#include <SDL.h>
#include <SDL_opengl.h>

namespace engine {
namespace sdl2 {

class GL_window {
public:
    GL_window(std::unique_ptr<SDL_window> window_handle);
    void update();
    virtual ~GL_window();

    SDL_GLContext get() const;
    void reset(SDL_GLContext context);

    SDL_window& get_sdl_window() const;

    Keycode last_key_pressed() const;

    GL_window& operator=(GL_window&&);
    GL_window(GL_window&&);

private:
    SDL_GLContext sdl_gl_context;
    bool loaded_successfully;
    void create_context();

    std::unique_ptr<SdlKeyEvent> key_event_listener_;
    std::unique_ptr<SDL_window> window;
    std::unique_ptr<Renderer> renderer_;
};

}
}

#endif
