//
// Created by Maddog on 10/4/2015.
//

#include "sdl2/SDLWindow.h"

using namespace engine::sdl2;

SDLWindow::SDLWindow(SDL_Window* window)
 : window_handle_(window) {
}

SDLWindow::SDLWindow()
  : window_handle_(nullptr) {

}

void SDLWindow::Create() {
  if (SDL_WasInit(SDL_INIT_EVERYTHING) == 0) {
  }

  window_handle_ = SDL_CreateWindow("Game Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600,
                                    SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  if (window_handle_ == nullptr) {
  }

}

SDLWindow::~SDLWindow() {
  if (window_handle_ != nullptr) {
    SDL_DestroyWindow(window_handle_);
  }
}
