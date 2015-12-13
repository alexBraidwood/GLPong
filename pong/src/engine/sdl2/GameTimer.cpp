//
// Created by alex on 12/12/15.
//

#include <sdl2/GameTimer.h>
#include <SDL.h>

using namespace engine::sdl2;

auto Game_timer::start() -> void
{
    is_running = true;
    start_time = SDL_GetTicks();
}

auto Game_timer::stop() -> void
{
    is_running = false;
    stop_time = start_time;
    start_time = 0;
}

auto Game_timer::delta_time() const -> int
{
    return (SDL_GetTicks() - start_time) / 1000;
}

auto Game_timer::stopped() const -> bool
{
    return !is_running;
};