#version 330 core

layout (location = 0)
in vec2 position;
in vec3 in_color;

out vec3 out_color;

void main() {
    out_color = in_color;
    gl_Position = vec4(position.x, position.y, 0.0, 1.0);
}