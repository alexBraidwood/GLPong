#include <engine/graphics/Rect.h>
#include <engine/Game.h>
#include <Paddle.h>

auto main(int argc, char* argv[]) -> int
{
    engine::Game g;
    auto playerOnePaddle = std::make_unique<pong::Paddle>(
            "paddle_p1",
            engine::graphics::Rect((g.screen_width() - 150), g.screen_height() / 2, 25, 100)
    );
    g.add_game_object(std::move(playerOnePaddle));
    g.init();
    g.update();

    return 0;
}

