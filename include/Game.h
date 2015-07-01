//
// Created by alex on 6/8/15.
//

#ifndef PROTOTYPE_ACTION_GAME_H
#define PROTOTYPE_ACTION_GAME_H

#include "Renderer.h"
#include "InputHandler.h"

class Game {
public:
    Game();
    void update();

public:

private:
    //static void input_callback_ (GLFWwindow*, int, int, int, int);
    static std::shared_ptr<InputHandler> input_handler_;

    std::shared_ptr<Renderer> renderer_;
};

#endif //PROTOTYPE_ACTION_GAME_H
