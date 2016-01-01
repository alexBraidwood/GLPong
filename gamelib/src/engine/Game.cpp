//
// Created by alex on 6/8/15.
//

#include "Game.h"
#include <SDL.h>


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

auto Game::init() -> void
{
    renderer->set_render_color(engine::graphics::Color::black());
}

auto Game::update() -> void
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
        if (event_handler->last_event() == Event_type::QuitEvent
                || event_handler->last_key_event() == Keycode::Escape) {
            SDL_Quit();
            is_running = false;
        }
        for (auto& pair : object_map) {
            auto& object = pair.second;
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

auto Game::add_game_object(std::unique_ptr<Game_object> object) -> void
{
    object_map.insert(std::make_pair(object->get_tag(), std::move(object)));
}

auto Game::remove_game_object(const std::string tag) -> void
{
    object_map.erase(tag);
}

auto Game::screen_height() const -> int
{
    return screen_h;
}

auto Game::screen_width() const -> int
{
    return screen_w;
}

