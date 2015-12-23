//
// Created by alex on 12/12/15.
//

#ifndef GLPONG_GAMETIMER_H
#define GLPONG_GAMETIMER_H

#include <chrono>

namespace engine {
namespace sdl2 {

using timestamp = std::chrono::time_point<std::chrono::high_resolution_clock>;

struct Game_timer {
    Game_timer() :
            is_running{false} {}

    void start();
    void stop();
    float delta_time();
    bool stopped() const;

private:
    bool is_running;
    timestamp start_time;
    timestamp stop_time;
    timestamp last_dt;
};

}
}

#endif //GLPONG_GAMETIMER_H
