//
// Created by alex on 6/8/15.
//

#pragma once

#include "Renderer.h"
#include "GLWindow.h"
#include "ListenerType.h"
#include "Observer.h"
#include <map>

namespace engine
{

    class Game
    {
    public:
        Game();

        void Update();

    public:
        void Subscribe(ListenerType type, std::shared_ptr<Observer> observer);
        void Unsubscribe(ListenerType type, std::shared_ptr<Observer> observer);

    private:
        std::shared_ptr<Renderer> renderer_;
        std::unique_ptr<engine::sdl2::GLWindow> window_;

        std::map<ListenerType, std::shared_ptr<Event>> observers_;
        bool is_running;
    };
}

