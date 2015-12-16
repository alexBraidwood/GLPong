//
// Created by alex on 6/8/15.
//

#include "Game.h"
#include <pong/Paddle.h>


using namespace engine;
using namespace engine::sdl2;

Game::Game()
    : event_handler{new Event_handler},
      screen_w{800},
      screen_h{600}
{
    window = SDL_window::create(800, 600);
    renderer = std::make_unique<SDL_renderer>(SDL_CreateRenderer(window->get(), -1, SDL_RENDERER_ACCELERATED));
    is_running = true;
}

auto Game::Init() -> void
{
    renderer->set_render_color(engine::graphics::Color::black());
    game_objects.push_back(std::make_unique<pong::Paddle>(
            engine::graphics::Rect((screen_w - 150), screen_h / 2, 25, 100)
    ));
}

auto Game::Update() -> void
{
    using namespace engine::graphics;
    if (timer.stopped()) {
        timer.start();
    }
    while (is_running) {
        auto dt = timer.delta_time();
        renderer->clear(graphics::Color::black());
        event_handler->handle_events();
        renderer->set_render_color(graphics::Color::white());
        renderer->draw_circle(Circle(300.0, 300.0, 10.0));
        if (event_handler->last_event() == EventType::QuitEvent
                || event_handler->last_key_event() == Keycode::Escape) {
            SDL_Quit();
            is_running = false;
        }
        for (auto& object : game_objects) {
            object->do_update(*event_handler, dt);
            object->do_draw(*renderer);
        }
        renderer->present();

        // We need to Delay if the framerate is ridiculous
        if (dt < (1000 / 60)) {
            SDL_Delay(int(((1000 / 60) - dt) + 0.5));
        }
    }
    timer.stop();
}

auto Game::game_timer() const -> const Game_timer&
{
    return timer;
}


