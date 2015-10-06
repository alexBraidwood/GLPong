//
// Created by alex on 6/8/15.
//

#ifndef ENGINE_RENDERER
#define ENGINE_RENDERER

#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <GL/gl.h>
#include "sdl2/GLWindow.h"

#include <Graphics/glew.h>
#include <SDL.h>

namespace engine {
class Renderer final {
 public:
  explicit Renderer();
  ~Renderer();
  void Init();
  void Update();

  GLuint CompileShader(std::string shader, GLenum shader_type, int element_count) const;
  std::string LoadShader(const std::string &shader_location) const;
  std::string ShaderCompilationResult(const GLuint shader) const;



 private:
  GLuint shader_program_;
  GLuint VAO_;
  GLuint VBO_;
};
}

#endif