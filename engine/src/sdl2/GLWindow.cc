//
// Created by alz12_000 on 6/30/2015.
//

#include "sdl2/GLWindow.h"

using namespace engine::sdl2;

GLWindow::GLWindow(std::unique_ptr<SDLWindow> window)
  : window_(std::move(window)),
    renderer_(new Renderer),
    key_event_listener_(new SdlKeyEvent) {
  window_->Create();
  sdl_gl_context_ = window_->CreateGLContext();
  renderer_->Init();
}

GLWindow::~GLWindow() {
  // TODO(): I need a better home, destroy me in a smarter way
  SDL_GL_DeleteContext(sdl_gl_context_);
}

auto GLWindow::LastKeyPress() const -> Keycode {
  return FromSdlKeycode(key_event_listener_->key_pressed());
}

auto GLWindow::Update() -> void {
  SDL_GL_SwapWindow(*window_);
  SDL_Event e;
  SDL_PollEvent(&e);
  renderer_->Update();
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