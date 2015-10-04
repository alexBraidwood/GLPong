#include "Game.h"

int main(int argc, char *argv[]) {
  auto g = std::make_unique<engine::Game>();
  g->Update();

  return 0;
}

