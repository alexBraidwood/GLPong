//
// Created by alz12_000 on 6/30/2015.
//

#ifndef ENGINE_SDL2_GLWINDOW
#define ENGINE_SDL2_GLWINDOW

#include "SdlKeyEvent.h"
#include "SDL_window.h"
#include "Renderer.h"
#include "Keycode.h"

#include <memory>
#include <SDL.h>
#include <SDL_opengl.h>

namespace engine {
namespace sdl2 {
class GL_window {
public:
    GL_window(sdl_window window);
    void update();
    virtual ~GL_window();

    SDL_GLContext get() const;

    Keycode last_key_pressed() const;

private:
    // TODO(): Wrap me up in a data structure, I'm a void pointer on the inside!
    SDL_GLContext sdl_gl_context_;
    bool loaded_successfully_;

    std::unique_ptr<SdlKeyEvent> key_event_listener_;
    sdl_window window;
    std::unique_ptr<Renderer> renderer_;
};

struct GL_window_deleter {
  auto operator()(GL_window* window) -> void
  {
      SDL_GL_DeleteContext(window);
  }
};

using gl_window = std::unique_ptr<GL_window, GL_window_deleter>;

}
}

#endif
