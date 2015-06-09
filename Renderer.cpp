//
// Created by alex on 6/8/15.
//

#include "Renderer.h"
#include <fstream>

GLfloat vertices[] = {
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f,
  0.0f, 0.5f, 0.0f
};

Renderer::Renderer() {
    init();
}

void Renderer::init() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window_ = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
    if (window_ == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window_);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return;
    }

    glViewport(0, 0, 800, 600);

    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    GLuint vertex_shader;
    vertex_shader = glCreateShader(GL_VERTEX_SHADER);

    auto vertex_shader_source = load_shader("Shaders/vertex_shader.glsl");
    auto vertex_shader_cstring = vertex_shader_source.c_str();
    int vertex_shader_length = vertex_shader_source.length();

    glShaderSource(vertex_shader, 1, &vertex_shader_cstring, &vertex_shader_length);
    glCompileShader(vertex_shader);

    std::cout << shader_compilation_result(vertex_shader) << std::endl;
}

GLuint Renderer::compile_shader(std::string shader, ) const {
    auto shader_source = load_shader(shader);
    auto shader_cstring = shader_source.c_str();
    int shader_length = shader_source.length();
    glShaderSource()
}

std::string Renderer::shader_compilation_result(const GLuint shader) const {
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if (false == success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::string result("Error, Shader compilation failed: ");
        result.append(infoLog);
        return result;
    }

    return "Success";
}

std::string Renderer::load_shader(const std::string& shader_location) const {
    std::ifstream input(shader_location);

    if (false == input.is_open()) {
        return "Couldn't Open File";
    }

    std::string result;

    // Reserve the size of the file
    input.seekg(0, std::ios::end);
    result.reserve(input.tellg());
    input.seekg(0, std::ios::beg);

    // Assign the file contents to the string
    result.assign((std::istreambuf_iterator<char>(input)),
                    std::istreambuf_iterator<char>());

    return result;
}

GLFWwindow* Renderer::window() const {
    return window_;
}

void Renderer::update() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window_);
}

