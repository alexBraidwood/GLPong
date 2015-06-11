//
// Created by alex on 6/8/15.
//

#ifndef PROTOTYPE_ACTION_RENDERER_H
#define PROTOTYPE_ACTION_RENDERER_H

#include <iostream>
#include <memory>
#include <functional>

#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Renderer final {
public:
    explicit Renderer();
    ~Renderer() = default;

    GLFWwindow* window() const;
    void init();
    void update();

    GLuint compile_shader(std::string shader, GLenum shader_type, int element_count) const;
    std::string load_shader(const std::string& shader_location) const;
    std::string shader_compilation_result(const GLuint shader) const;

private:
    GLFWwindow* window_;
    GLuint shader_program_;
    GLuint VAO_;
    GLuint VBO_;

};


#endif //PROTOTYPE_ACTION_RENDERER_H
