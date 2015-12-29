#include <gtest/gtest.h>

auto main (int argc, char* argv[]) -> int {
  ::testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  std::getchar();
}