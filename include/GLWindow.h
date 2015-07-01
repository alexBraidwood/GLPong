//
// Created by alz12_000 on 6/30/2015.
//

#pragma once

#include <memory>
#include <SDL.h>
#include <SDL_opengl.h>

namespace sdl2 {


    struct SDLWindowDestroyer
    {
        void operator()(SDL_Window* w) const
        {
            SDL_DestroyWindow(w);
        }
    };

    class GLWindow {
    public:
        GLWindow();
        ~GLWindow();

        SDL_GLContext sdl_gl_context();

    private:
        std::unique_ptr<SDL_Window, SDLWindowDestroyer> sdl_window_;
        SDL_GLContext sdl_gl_context_;
        bool loaded_successfully_;
    };
}

