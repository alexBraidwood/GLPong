//
// Created by alex on 12/12/15.
//

#include <engine/graphics/Color.h>

using namespace engine::graphics;

auto Color::red() -> Color
{
    return Color(255, 0, 0);
}

auto Color::blue() -> Color
{
    return Color(0, 0, 255);
}

auto Color::green() -> Color
{
    return Color(0, 255, 0);
}

auto Color::white() -> Color
{
    return Color();
}