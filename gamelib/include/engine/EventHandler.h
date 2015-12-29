//
// Created by Maddog on 12/5/2015.
//

#ifndef GLPONG_EVENTHANDLER_H
#define GLPONG_EVENTHANDLER_H

#include "sdl2/Key_event.h"
#include "sdl2/Event_type.h"

namespace engine {
class Event_handler {
    sdl2::Event_type last_event_type_;
    sdl2::Key_event last_key_event_;

public:
    void handle_events();
    const sdl2::Event_type& last_event() const;
    const sdl2::Key_event& last_key_event() const;
};
}


#endif //GLPONG_EVENTHANDLER_H
