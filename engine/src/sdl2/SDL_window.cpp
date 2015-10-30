//
// Created by Maddog on 10/4/2015.
//

#include "sdl2/SDL_window.h"
#include <iostream>
#include <stdexcept>

using namespace engine::sdl2;


SDL_window::SDL_window(SDL_Window* handle)
    : window_handle{handle}
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


auto SDL_window::create(int height, int width) -> std::unique_ptr<SDL_window>
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) < 0) {
        // TODO(): Handle the error here
        std::cout << "Failed to initialize SDL properly " << SDL_GetError() << std::endl;
    }

    auto window_handle = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if (window_handle == nullptr) {
        // TODO(): Handle the error here
    }

    return std::move(std::make_unique<SDL_window>(window_handle));
}

auto SDL_window::reset(SDL_Window* window) -> void
{
    window_handle = window;
}


SDL_window::SDL_window(SDL_window&& window)
{
    if(this != &window) {
        this->window_handle = window.get();
        window.reset(nullptr);
    }
}

SDL_window& SDL_window::operator=(SDL_window&& window)
{
    if (this != &window) {
        this->window_handle = window.get();
        window.reset(nullptr);
    }
    return *this;
}
