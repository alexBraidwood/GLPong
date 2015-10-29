//
// Created by Maddog on 10/4/2015.
//

#include "sdl2/SDL_window.h"

using namespace engine::sdl2;


SDL_window::SDL_window()
        :window_handle_(nullptr)
{

}

auto SDL_window::get() const -> SDL_Window*
{

}


auto SDL_window::create() -> void
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER)<0) {
        // TODO(): Handle the error here
    }

    window_handle_ = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (window_handle_==nullptr) {
        // TODO(): Handle the error here
    }

}

auto SDL_window::CreateGLContext() const -> SDL_GLContext
{
    auto glContext = SDL_GL_CreateContext(*this);
    if (glContext==nullptr) {
        // TODO(): Handle the error here
        return nullptr;
    }
    return glContext;
}

SDL_window::~SDL_window()
{
    if (window_handle_!=nullptr) {
        SDL_DestroyWindow(window_handle_);
    }
}
