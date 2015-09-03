//
// Created by alex on 7/5/15.
//

#pragma once

#include <memory>
#include "EventType.h"

namespace engine
{
    template <typename T>
    class Observer;

    template <typename T>
    class Subject
    {
    public:
        virtual void AttachObserver(std::shared_ptr<Observer<T>> observer) = 0;

        virtual void DetachObserver(std::shared_ptr<Observer<T>> observer) = 0;

        virtual void NotifyObservers() = 0;

        virtual void Register(T event);

        virtual T& last_event() const = 0;
    };
}


