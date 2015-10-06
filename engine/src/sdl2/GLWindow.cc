//
// Created by alz12_000 on 6/30/2015.
//

#include "GLWindow.h"
#include <iostream>

using namespace engine::sdl2;

GLWindow::GLWindow() {
  key_event_listener_ = std::make_shared<SdlKeyEvent>();
}

GLWindow::~GLWindow() {
  // TODO(): I need a better home, destroy me in a smarter way
  SDL_GL_DeleteContext(sdl_gl_context_);
}

SDL_GLContext GLWindow::sdl_gl_context() {
  return sdl_gl_context_;
}

std::shared_ptr<SdlKeyEvent> GLWindow::key_event_listener() {
  return key_event_listener_;
}

void GLWindow::Update() {
  //SDL_GL_SwapWindow(*sdl_window_);
  SDL_Event e;
  SDL_PollEvent(&e);
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