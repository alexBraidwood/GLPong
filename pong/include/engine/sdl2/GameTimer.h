//
// Created by alex on 12/12/15.
//

#ifndef GLPONG_GAMETIMER_H
#define GLPONG_GAMETIMER_H

namespace engine {
namespace sdl2 {

struct Game_timer {
    Game_timer() :
            is_running{false}, start_time{0} {}

    void start();
    void stop();
    int delta_time() const;
    bool stopped() const;

private:
    bool is_running;
    unsigned int start_time;
    unsigned int stop_time;
};

}
}

#endif //GLPONG_GAMETIMER_H
