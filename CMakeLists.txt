cmake_minimum_required(VERSION 3.2)
project(prototype_action)

include_directories(/usr/include/GLFW)
include_directories(include)

find_package(OpenGL REQUIRED)

set(SOURCES
src/main.cpp
src/GraphicsComponent.cpp
src/Renderer.cpp
src/Game.cpp
src/InputHandler.cpp
src/glew/glew.c
src/glew/glewinfo.c
src/glew/visualinfo.c
include/Graphics/glew.h
include/Graphics/glxew.h
include/Graphics/wglew.h
include/Components/GraphicsComponent.h
include/Renderer.h
include/Game.h
include/InputHandler.h)

if (OpenGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
endif(OpenGL_FOUND)

file(MAKE_DIRECTORY Shaders)

file(COPY
Shaders/vertex_shader.glsl
Shaders/fragment_shader.glsl
DESTINATION Shaders)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

add_executable(prototype_action ${SOURCES})
target_link_libraries(prototype_action glfw ${OPENGL_LIBRARY} ${GLFW_LIBRARIES} ${SDL2_LIBRARIES})