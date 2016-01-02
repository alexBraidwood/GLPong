#include <engine/graphics/Rect.h>
#include <engine/Game.h>
#include <Paddle.h>
#include <Ball.h>

auto main(int argc, char* argv[]) -> int
{
    engine::Game g;
    auto playerOnePaddle = std::make_unique<pong::Paddle>(
            "paddle_p1",
            engine::graphics::Rect((g.screen_width() - 150), g.screen_height() / 2, 25, 100)
    );
    auto ball = std::make_unique<pong::Ball>(
            "ball",
            engine::graphics::Circle(g.screen_width() / 2 , g.screen_height() / 2, 10.0)
    );

    ball->add_velocity(glm::vec2(1.0f, 1.0f));
    g.add_game_object(std::move(playerOnePaddle));
    g.add_game_object(std::move(ball));
    g.init();
    g.update();

    return 0;
}

