//
// Created by Maddog on 12/5/2015.
//

#include <Eventhandler.h>

using namespace engine;

auto Event_handler::handle_events() -> void
{
    SDL_Event event;
    SDL_PollEvent(&event);
    last_event_type_ = sdl2::from_SDL_event_type(event.type);
    switch(last_event_type_) {
    case sdl2::EventType::KeyPressedEvent:
        last_key_event_.key_pressed(event.key.keysym.sym);
        break;
    case sdl2::EventType::KeyReleasedEvent:
        last_key_event_.key_released(event.key.keysym.sym);
        break;
    }
}

auto Event_handler::last_event() const -> const sdl2::EventType&
{
    return last_event_type_;
}

auto Event_handler::last_key_event() const -> const sdl2::SdlKeyEvent&
{
    return last_key_event_;
}