//
// Created by Maddog on 12/5/2015.
//

#ifndef GLPONG_EVENTHANDLER_H
#define GLPONG_EVENTHANDLER_H

#include <engine/sdl2/SdlKeyEvent.h>
#include <engine/sdl2/EventType.h>

namespace engine {
class Event_handler {
    sdl2::EventType last_event_type_;
    sdl2::SdlKeyEvent last_key_event_;

public:
    void handle_events();
    const sdl2::EventType& last_event() const;
    const sdl2::SdlKeyEvent& last_key_event() const;
};
}


#endif //GLPONG_EVENTHANDLER_H
