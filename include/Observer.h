//
// Created by alex on 7/5/15.
//

#pragma once


#include "Event.h"

namespace engine
{
    class Observer
    {
    public:
        virtual void EventUpdate(const Event& event) = 0;
    };
}


