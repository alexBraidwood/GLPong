cmake_minimum_required(VERSION 3.2)
project(PongProject)

add_definitions(-std=c++14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${GLPong_SOURCE_DIR}/gamelib/cmake")

set(GLPong_Binaries ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(GLPong_BINARY_DIR "${GLPong_Binaries}")

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
include_directories(gamelib/include)

# Subprojects placed here
add_subdirectory(gamelib)
add_subdirectory(gamelib_tests)
add_subdirectory(pong)

set(SOURCE_FILES main.cpp)

add_executable(Game {SOURCE_FILES})

if (WIN32)
    target_link_libraries(Game ${OPENGL_LIBRARY} ${SDL2_LIBRARIES} ${LINK_OPTIONS})
else(WIN32)
    target_link_libraries(Gamelib ${LINK_OPTIONS} ${OPENGL_LIBRARY} ${SDL2_LIBRARIES})
endif(WIN32)

