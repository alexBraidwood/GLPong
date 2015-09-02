cmake_minimum_required(VERSION 3.2)
project(prototype_action)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${prototype_action_SOURCE_DIR}/cmake")

include_directories(include)

find_package(OpenGL REQUIRED)

if (WIN32)
    include_directories(SDL2/i686-w64-mingw32/include/SDL2)
    set(BINARIES SDL2/i686-w64-mingw32/bin/SDL2.dll)
    link_directories(SDL2/i686-w64-mingw32/lib)
    link_directories(SOIL)
    set(LINK_OPTIONS mingw32 SDL2Main SDL2)
    add_definitions(-DGLEW_STATIC)
else()
    find_package(SDL2 REQUIRED)
    include_directories(/usr/include/SDL2)
    link_directories(SOIL)
    set(LINK_OPTIONS SDL2)
endif()


set(SOURCES
src/main.cpp
src/Components/GraphicsComponent.cpp
src/engine/Renderer.cpp
src/engine/Game.cpp
src/glew/glew.c
src/sdl2/GLWindow.cpp
src/engine/Observer.cpp
src/sdl2/SdlKeyEvent.cpp
include/ListenerType.h
include/EventType.h
include/SdlKeyEvent.h
include/Observer.h
include/Event.h
include/GLWindow.h
include/GL/glew.h
include/GL/glxew.h
include/GL/wglew.h
include/Components/GraphicsComponent.h
include/Renderer.h
include/Game.h
include/Graphics/SOIL.h)

if (OpenGL_FOUND)
    include_directories(${OPENGL_INCLUDE_DIR})
endif(OpenGL_FOUND)

file(MAKE_DIRECTORY Shaders)

file(COPY
Shaders/vertex_shader.glsl
Shaders/fragment_shader.glsl
DESTINATION Shaders)

file(COPY
${BINARIES}
DESTINATION /)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_executable(prototype_action ${SOURCES})
if (WIN32)
    target_link_libraries(prototype_action ${OPENGL_LIBRARY} ${SDL2_LIBRARIES} ${LINK_OPTIONS})
else()
    target_link_libraries(prototype_action ${LINK_OPTIONS} ${OPENGL_LIBRARY} ${SDL2_LIBRARIES})
endif()
