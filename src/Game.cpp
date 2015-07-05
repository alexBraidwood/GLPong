//
// Created by alex on 6/8/15.
//

#include "Game.h"

using namespace engine;

Game::Game()
{
    renderer_ = std::make_shared<Renderer>();
}

void Game::Update()
{
    // When do we close the window?
    // I have no idea, yet, let the renderer decide
    renderer_->Update();
}

//void Game::input_callback_(GLFWwindow* window, int key, int scancode, int action, int mode) {
//    std::cout << "Calling Callback" << std::endl;
//
//    if (action == GLFW_PRESS) {
//        Game::input_handler_->key_pressed(key);
//    }
//
//    if (action == GLFW_RELEASE) {
//        Game::input_handler_->key_released(key);
//    }
//}
