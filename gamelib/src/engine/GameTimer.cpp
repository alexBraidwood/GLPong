//
// Created by alex on 12/12/15.
//

#include <GameTimer.h>
#include <chrono>

using namespace engine::sdl2;
using namespace std::chrono;

auto Game_timer::start() -> void
{
    is_running = true;
    start_time = high_resolution_clock::now();
    last_dt = start_time;
}

auto Game_timer::stop() -> void
{
    is_running = false;
    stop_time = start_time;
    start_time = timestamp();
}

auto Game_timer::delta_time() -> float
{
    auto current_dt = high_resolution_clock::now();
    auto diff = duration_cast<nanoseconds>(current_dt - last_dt);
    last_dt = current_dt;
    float dt = diff.count() / 1000000000.f;
    return dt;
}

auto Game_timer::stopped() const -> bool
{
    return !is_running;
};