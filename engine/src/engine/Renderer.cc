//
// Created by alex on 6/8/15.
//

#include "Renderer.h"
#include <fstream>
#include <sstream>
#include <SDL.h>

using namespace engine;

GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
};

Renderer::Renderer() {
}

void Renderer::Init() {
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);


  glewExperimental = GL_TRUE;
  if (glewInit() != GLEW_OK) {
    std::cout << "Failed to initialize GLEW" << std::endl;
    return;
  }

  glViewport(0, 0, 800, 600);

  auto vertex_shader = CompileShader("Shaders/vertex_shader.glsl", GL_VERTEX_SHADER, 1);
  ShaderCompilationResult(vertex_shader);

  auto fragment_shader = CompileShader("Shaders/fragment_shader.glsl", GL_FRAGMENT_SHADER, 1);
  ShaderCompilationResult(fragment_shader);

  shader_program_ = glCreateProgram();
  glAttachShader(shader_program_, vertex_shader);
  glAttachShader(shader_program_, fragment_shader);
  glLinkProgram(shader_program_);

  glDeleteShader(vertex_shader);
  glDeleteShader(fragment_shader);

  glGenVertexArrays(1, &VAO_);
  glGenBuffers(1, &VBO_);
  glBindVertexArray(VAO_);
  glBindBuffer(GL_ARRAY_BUFFER, VBO_);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid *) 0);
  glEnableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glUseProgram(shader_program_);
  glBindVertexArray(VAO_);
}

GLuint Renderer::CompileShader(std::string shader_file, GLenum shader_type, int element_count) const {
  GLuint shader;
  shader = glCreateShader(shader_type);

  auto shader_source = LoadShader(shader_file);
  auto shader_cstring = shader_source.c_str();
  int shader_length = shader_source.length();

  glShaderSource(shader, element_count, &shader_cstring, &shader_length);
  glCompileShader(shader);

  return shader;
}

std::string Renderer::ShaderCompilationResult(const GLuint shader) const {
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

std::string Renderer::LoadShader(const std::string &shader_location) const {
  std::ifstream input(shader_location);
  std::string result;

  if (false == input.is_open()) {
    return "Couldn't Open File";
  }

  input.seekg(0, std::ios::end);
  result.reserve(input.tellg());
  input.seekg(0, std::ios::beg);

  result.assign((std::istreambuf_iterator<char>(input)),
                std::istreambuf_iterator<char>());

  return result;
}

void Renderer::Update() {
  glClear(GL_COLOR_BUFFER_BIT);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

Renderer::~Renderer() {
  glBindVertexArray(0);
}

