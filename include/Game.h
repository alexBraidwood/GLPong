//
// Created by alex on 6/8/15.
//

#pragma once

#include "Renderer.h"
#include "InputHandler.h"

namespace engine
{

    class Game
    {
    public:
        Game();

        void Update();

    public:

    private:
        InputHandler input_handler_;
        std::shared_ptr<Renderer> renderer_;
    };
}

