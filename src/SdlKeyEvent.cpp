//
// Created by alex on 7/5/15.
//

#include "SdlKeyEvent.h"
#include "Observer.h"
#include <algorithm>
#include <iostream>

using namespace engine::sdl2;

void SdlKeyEvent::AttachObserver(std::shared_ptr<Observer> observer)
{
    observers_.push_back(observer);
}

void SdlKeyEvent::DetachObserver(std::shared_ptr<Observer> observer)
{
    auto it = std::find(observers_.begin(), observers_.end(), observer);
    observers_.erase(it);
}

void SdlKeyEvent::NotifyObservers()
{
    for (auto observer : observers_) {
        observer->EventOccured(std::shared_ptr<Event>(this));
    }
}

SDL_Keycode SdlKeyEvent::last_key_pressed()
{
    return last_key_pressed_;
}

SDL_Keycode SdlKeyEvent::last_key_released()
{
    return last_key_released_;
}

void SdlKeyEvent::last_key_pressed(SDL_Keycode key)
{
    last_key_pressed_ = key;
    NotifyObservers();
}

void SdlKeyEvent::last_key_released(SDL_Keycode key)
{
    last_key_released_ = key;
    NotifyObservers();
}