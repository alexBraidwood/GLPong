//
// Created by alex on 6/8/15.
//

#include "InputHandler.h"

InputHandler::InputHandler(){
}

void InputHandler::update() {
    // Update Logic
//    glfwPollEvents();
}

void InputHandler::key_pressed(int key_code) {
    keys_[key_code] = true;
}

void InputHandler::key_released(int key_code) {
    keys_[key_code] = false;
}

bool InputHandler::is_key_down(int key_code) {
    return keys_[key_code];
}

bool InputHandler::is_key_up(int key_code) {
    return !keys_[key_code];
}

//void InputHandler::keys_init() {
//    keys_[GLFW_KEY_SPACE] = false;
//    keys_[GLFW_KEY_APOSTROPHE] = false;
//    keys_[GLFW_KEY_COMMA] = false;
//    keys_[GLFW_KEY_MINUS] = false;
//    keys_[GLFW_KEY_PERIOD] = false;
//    keys_[GLFW_KEY_SLASH] = false;
//    keys_[GLFW_KEY_0] = false;
//    keys_[GLFW_KEY_1] = false;
//    keys_[GLFW_KEY_2] = false;
//    keys_[GLFW_KEY_3] = false;
//    keys_[GLFW_KEY_4] = false;
//    keys_[GLFW_KEY_5] = false;
//    keys_[GLFW_KEY_6] = false;
//    keys_[GLFW_KEY_7] = false;
//    keys_[GLFW_KEY_8] = false;
//    keys_[GLFW_KEY_9] = false;
//    keys_[GLFW_KEY_SEMICOLON] = false;
//    keys_[GLFW_KEY_EQUAL] = false;
//    keys_[GLFW_KEY_A] = false;
//    keys_[GLFW_KEY_B] = false;
//    keys_[GLFW_KEY_C] = false;
//    keys_[GLFW_KEY_D] = false;
//    keys_[GLFW_KEY_E] = false;
//    keys_[GLFW_KEY_F] = false;
//    keys_[GLFW_KEY_G] = false;
//    keys_[GLFW_KEY_H] = false;
//    keys_[GLFW_KEY_I] = false;
//    keys_[GLFW_KEY_J] = false;
//    keys_[GLFW_KEY_K] = false;
//    keys_[GLFW_KEY_L] = false;
//    keys_[GLFW_KEY_M] = false;
//    keys_[GLFW_KEY_N] = false;
//    keys_[GLFW_KEY_O] = false;
//    keys_[GLFW_KEY_P] = false;
//    keys_[GLFW_KEY_Q] = false;
//    keys_[GLFW_KEY_R] = false;
//    keys_[GLFW_KEY_S] = false;
//    keys_[GLFW_KEY_T] = false;
//    keys_[GLFW_KEY_U] = false;
//    keys_[GLFW_KEY_V] = false;
//    keys_[GLFW_KEY_W] = false;
//    keys_[GLFW_KEY_X] = false;
//    keys_[GLFW_KEY_Y] = false;
//    keys_[GLFW_KEY_Z] = false;
//    keys_[GLFW_KEY_LEFT_BRACKET] = false;
//    keys_[GLFW_KEY_RIGHT_BRACKET] = false;
//    keys_[GLFW_KEY_BACKSLASH] = false;
//    keys_[GLFW_KEY_GRAVE_ACCENT] = false;
//    keys_[GLFW_KEY_WORLD_1] = false;
//    keys_[GLFW_KEY_WORLD_2] = false;
//    keys_[GLFW_KEY_ESCAPE] = false;
//    keys_[GLFW_KEY_ENTER] = false;
//    keys_[GLFW_KEY_TAB] = false;
//    keys_[GLFW_KEY_BACKSPACE] = false;
//    keys_[GLFW_KEY_INSERT] = false;
//    keys_[GLFW_KEY_DELETE] = false;
//    keys_[GLFW_KEY_RIGHT] = false;
//    keys_[GLFW_KEY_LEFT] = false;
//    keys_[GLFW_KEY_DOWN] = false;
//    keys_[GLFW_KEY_UP] = false;
//    keys_[GLFW_KEY_PAGE_UP] = false;
//    keys_[GLFW_KEY_PAGE_DOWN] = false;
//    keys_[GLFW_KEY_HOME] = false;
//    keys_[GLFW_KEY_END] = false;
//    keys_[GLFW_KEY_CAPS_LOCK] = false;
//    keys_[GLFW_KEY_SCROLL_LOCK] = false;
//    keys_[GLFW_KEY_NUM_LOCK] = false;
//    keys_[GLFW_KEY_PRINT_SCREEN] = false;
//    keys_[GLFW_KEY_PAUSE] = false;
//    keys_[GLFW_KEY_F1] = false;
//    keys_[GLFW_KEY_F2] = false;
//    keys_[GLFW_KEY_F3] = false;
//    keys_[GLFW_KEY_F4] = false;
//    keys_[GLFW_KEY_F5] = false;
//    keys_[GLFW_KEY_F6] = false;
//    keys_[GLFW_KEY_F7] = false;
//    keys_[GLFW_KEY_F8] = false;
//    keys_[GLFW_KEY_F9] = false;
//    keys_[GLFW_KEY_F10] = false;
//    keys_[GLFW_KEY_F11] = false;
//    keys_[GLFW_KEY_F12] = false;
//    keys_[GLFW_KEY_F13] = false;
//    keys_[GLFW_KEY_F14] = false;
//    keys_[GLFW_KEY_F15] = false;
//    keys_[GLFW_KEY_F16] = false;
//    keys_[GLFW_KEY_F17] = false;
//    keys_[GLFW_KEY_F18] = false;
//    keys_[GLFW_KEY_F19] = false;
//    keys_[GLFW_KEY_F20] = false;
//    keys_[GLFW_KEY_F21] = false;
//    keys_[GLFW_KEY_F22] = false;
//    keys_[GLFW_KEY_F23] = false;
//    keys_[GLFW_KEY_F24] = false;
//    keys_[GLFW_KEY_F25] = false;
//    keys_[GLFW_KEY_KP_0] = false;
//    keys_[GLFW_KEY_KP_1] = false;
//    keys_[GLFW_KEY_KP_2] = false;
//    keys_[GLFW_KEY_KP_3] = false;
//    keys_[GLFW_KEY_KP_4] = false;
//    keys_[GLFW_KEY_KP_5] = false;
//    keys_[GLFW_KEY_KP_6] = false;
//    keys_[GLFW_KEY_KP_7] = false;
//    keys_[GLFW_KEY_KP_8] = false;
//    keys_[GLFW_KEY_KP_9] = false;
//    keys_[GLFW_KEY_KP_DECIMAL] = false;
//    keys_[GLFW_KEY_KP_DIVIDE] = false;
//    keys_[GLFW_KEY_KP_MULTIPLY] = false;
//    keys_[GLFW_KEY_KP_SUBTRACT] = false;
//    keys_[GLFW_KEY_KP_ADD] = false;
//    keys_[GLFW_KEY_KP_ENTER] = false;
//    keys_[GLFW_KEY_KP_EQUAL] = false;
//    keys_[GLFW_KEY_LEFT_SHIFT] = false;
//    keys_[GLFW_KEY_LEFT_CONTROL] = false;
//    keys_[GLFW_KEY_LEFT_ALT] = false;
//    keys_[GLFW_KEY_LEFT_SUPER] = false;
//    keys_[GLFW_KEY_RIGHT_SHIFT] = false;
//    keys_[GLFW_KEY_RIGHT_ALT] = false;
//    keys_[GLFW_KEY_RIGHT_CONTROL] = false;
//    keys_[GLFW_KEY_RIGHT_SUPER] = false;
//    keys_[GLFW_KEY_MENU] = false;
//    keys_[GLFW_KEY_LAST] = false;
//
//
//}