//
// Created by Maddog on 10/4/2015.
//

#pragma once

#include <SDL.h>

namespace engine {
 namespace sdl2 {
   class SDLWindow {

    public:
     SDLWindow(SDL_Window *window);
     operator SDL_Window *() const {
       return window_handle_;
     }
    protected:
     virtual ~SDLWindow();

    private:
     SDL_Window *window_handle_;
   };
 }
}
