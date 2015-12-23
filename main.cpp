#include "engine/Game.h"

auto main(int argc, char* argv[]) -> int
{
    engine::Game g;
    g.Init();
    g.Update();

    return 0;
}

