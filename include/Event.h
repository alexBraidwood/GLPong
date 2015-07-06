//
// Created by alex on 7/5/15.
//

#pragma once

#include <memory>
#include "EventType.h"

namespace engine
{
    class Observer;

    class Event
    {
    public:
        virtual void AttachObserver(std::shared_ptr<Observer> observer) = 0;

        virtual void DetachObserver(std::shared_ptr<Observer> observer) = 0;

        virtual void NotifyObservers() = 0;
    };
}


