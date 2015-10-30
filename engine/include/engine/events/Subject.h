//
// Created by alex on 7/5/15.
//

#ifndef ENGINE_SUBJECT
#define ENGINE_SUBJECT

#include <memory>
#include "sdl2/EventType.h"

namespace engine {

template <class TObserver, typename TEventType>
class Subject {
public:
    virtual auto attach(const TObserver& observer) -> void
    {

    }

    virtual auto detach(const TObserver& observer) -> void
    {

    }

    virtual auto notify(const TEventType& event) -> void
    {

    }

private:

};
}

#endif

