//
// Created by alex on 7/5/15.
//

#pragma once

#include "Event.h"
#include "EventType.h"
#include <vector>

namespace engine
{
    namespace sdl2
    {
        class SdlKeyEvent : public engine::Event
        {
        public:
            void AttachObserver( std::shared_ptr<Observer> observer) override;

            void DetachObserver(std::shared_ptr<Observer> observer) override;

            void NotifyObservers() override;

            SDL_Keycode last_key_pressed();

            SDL_Keycode last_key_released();

            void last_key_pressed(SDL_Keycode key);

            void last_key_released(SDL_Keycode key);

        private:
            std::vector<std::shared_ptr<Observer>> observers_;
            SDL_Keycode last_key_pressed_;
            SDL_Keycode last_key_released_;
        };
    }
}



