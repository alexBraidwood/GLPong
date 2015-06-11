cmake_minimum_required(VERSION 3.2)
project(prototype_action)

include_directories(/usr/include/GLFW)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

set(SOURCES
main.cpp
Components/GraphicsComponent.cpp
Components/GraphicsComponent.h
Renderer.cpp
Renderer.h
Game.cpp
Game.h
InputHandler.cpp
InputHandler.h)

if (OpenGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
endif(OpenGL_FOUND)

if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif(GLEW_FOUND)

file(MAKE_DIRECTORY Shaders)

file(COPY
Shaders/vertex_shader.glsl
Shaders/fragment_shader.glsl
DESTINATION Shaders)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

add_executable(prototype_action ${SOURCES})
target_link_libraries(prototype_action glfw ${OPENGL_LIBRARY} ${GLFW_LIBRARIES})