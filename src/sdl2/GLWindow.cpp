//
// Created by alz12_000 on 6/30/2015.
//

#include "GLWindow.h"
#include <iostream>

using namespace engine::sdl2;

GLWindow::GLWindow() {
    loaded_successfully_ = true;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL couldn't be initialized! SDL_Error: " << SDL_GetError();
        loaded_successfully_ = false;
    } else {
        sdl_window_ = std::unique_ptr<SDL_Window, SDLWindowDestroyer>(
                SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
                                 SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN));
        if (sdl_window_ == nullptr) {
            std::cout << "Window couldn't be created! SDL_Error: " << SDL_GetError();
            loaded_successfully_ = false;
        } else {
            sdl_gl_context_ = SDL_GL_CreateContext(sdl_window_.get());
            if (sdl_gl_context_ == nullptr) {
                std::cout << "Failed to create OpenGL Context! SDL_Error: " << SDL_GetError();
            }
        }
    }

    key_event_listener_ = std::make_shared<SdlKeyEvent>();
}

GLWindow::~GLWindow()
{
    // TODO(): I need a better home, destroy me in a smarter way
    SDL_GL_DeleteContext(sdl_gl_context_);
}

SDL_GLContext GLWindow::sdl_gl_context()
{
    return sdl_gl_context_;
}

std::shared_ptr<SdlKeyEvent> GLWindow::key_event_listener()
{
    return key_event_listener_;
}

void GLWindow::Update()
{
    SDL_GL_SwapWindow(sdl_window_.get());
    SDL_Event e;
    SDL_PollEvent(&e);
    switch(e.type) {
        case SDL_QUIT:
            break;
        case SDL_KEYDOWN:
            key_event_listener_->key_pressed(e.key.keysym.sym);
            break;
        case SDL_KEYUP:
            key_event_listener_->key_released(e.key.keysym.sym);
            break;
    }
}