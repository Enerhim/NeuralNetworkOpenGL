#include <glad/glad.h>
#include <vector>
#include "Window.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"
#include "Polygon.hpp"

int main() {

  Window window(1600, 900, "nngl");
  Shader shader;
  Renderer renderer(0, 0, 1600, 900);

  std::vector<float> vertices = {
      0.8,   0.5f,
      0.0f, // Top Right
      0.5f,  -0.5f,
      0.0f, // Bottom Right
      -0.5f, -0.5f,
      0.0f, // Bottom Left
  };
  Polygon triangle(vertices, std::vector<unsigned int>{0, 1, 2});
  while (!window.shouldClose()) {
    window.processInput();
    renderer.clear(0.1f, 0.5f, 0.1f, 1.0f);
    shader.use();

    // The correspoding VBO and EBO are automatically bound when VAO is bound.
    renderer.drawElements(triangle.getVAO(), 3);
    window.swapBuffers();
    window.pollEvents();
  }
  return 0;
}
