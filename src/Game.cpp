//
// Created by alex on 6/8/15.
//

#include "Game.h"
#include <iostream>

std::shared_ptr<InputHandler> Game::input_handler_ = std::shared_ptr<InputHandler>(new InputHandler);

void Game::input_callback_(GLFWwindow* window, int key, int scancode, int action, int mode) {
    std::cout << "Calling Callback" << std::endl;

    if (action == GLFW_PRESS) {
        Game::input_handler_->key_pressed(key);
    }

    if (action == GLFW_RELEASE) {
        Game::input_handler_->key_released(key);
    }
}

Game::Game()
    : renderer_(new Renderer)
{
    glfwSetKeyCallback(renderer_->window(), Game::input_callback_);
}

void Game::update() {
    while (false == glfwWindowShouldClose(renderer_->window())) {
        Game::input_handler_->update();
        renderer_->update();

        if (Game::input_handler_->is_key_down(GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(renderer_->window(), GL_TRUE);
        }
    }
}
