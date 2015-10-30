//
// Created by Maddog on 10/4/2015.
//

#include "sdl2/SDL_window.h"
#include <iostream>
#include <stdexcept>

using namespace engine::sdl2;


SDL_window::SDL_window()
        :window_handle(nullptr)
{

}

SDL_window::~SDL_window()
{
    if (window_handle != nullptr) {
        SDL_DestroyWindow(window_handle);
    }
}

auto SDL_window::get() const -> SDL_Window*
{
    return window_handle;
}


auto SDL_window::create() -> void
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) < 0) {
        // TODO(): Handle the error here
        std::cout << "Failed to initialize SDL properly " << SDL_GetError() << std::endl;
    }

    window_handle = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_OPENGL);
    if (window_handle == nullptr) {
        // TODO(): Handle the error here
    }

}

auto SDL_window::reset(SDL_Window* window) -> void
{
    window_handle = window;
}

auto SDL_window::create_GL_context() const -> SDL_GLContext
{
    auto glContext = SDL_GL_CreateContext(get());
    if (glContext == nullptr) {
        // TODO(): Handle the error here
        return nullptr;
    }
    return glContext;
}
SDL_window::SDL_window(SDL_window&& window)
{

}
SDL_window& SDL_window::operator=(SDL_window&& window)
{
    if (this != &window) {
        this->window_handle = window.get();
        window.reset(nullptr);
    }
    return *this;
}
