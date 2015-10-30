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
    GL_window(sdl_window_handle window_handle);
    void update();
    virtual ~GL_window() {};

    SDL_GLContext get() const;
    void reset(SDL_GLContext context);

    sdl2::SDL_window& SDL_window() const;

    Keycode last_key_pressed() const;

    GL_window& operator=(GL_window&&);
    GL_window(GL_window&&);

private:
    SDL_GLContext sdl_gl_context;
    bool loaded_successfully;

    std::unique_ptr<SdlKeyEvent> key_event_listener_;
    sdl_window_handle window;
    std::unique_ptr<Renderer> renderer_;
};

struct GL_window_deleter {
  auto operator()(GL_window* window) -> void
  {
      SDL_GL_DeleteContext(window->get());
  }
};

using gl_window = std::unique_ptr<GL_window, GL_window_deleter>;

}
}

#endif
