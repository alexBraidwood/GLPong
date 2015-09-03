//
// Created by alex on 7/5/15.
//

#pragma once

namespace engine
{
    template <typename T>
    class Subject;

    template <typename T>
    class Observer
    {
    public:
        virtual void Update(const Subject<T>& event) = 0;
    };
}


