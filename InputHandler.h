//
// Created by alex on 6/8/15.
//

#ifndef PROTOTYPE_ACTION_INPUTHANDLER_H
#define PROTOTYPE_ACTION_INPUTHANDLER_H

#include <functional>
#include <memory>
#include <SDL.h>
#include <GLFW/glfw3.h>
#include <map>
#include <iostream>

class InputHandler {
public:
    InputHandler();

    ~InputHandler() = default;
    InputHandler(const InputHandler&) = delete;
    InputHandler operator=(const InputHandler&) = delete;

    void update();
    void key_pressed(int key_code);
    void key_released(int key_code);
    bool is_key_down(int key_code);
    bool is_key_up(int key_code);

private:

    std::map<int, bool> keys_;

    void keys_init();
};


#endif //PROTOTYPE_ACTION_INPUTHANDLER_H
