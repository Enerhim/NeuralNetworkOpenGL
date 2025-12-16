#include <glad/glad.h>
#include "Window.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"
#include "Line.hpp"
#include "Circle.hpp"

int main() {

  Window window(1600, 900, "nngl");
  Shader shader;
  Renderer renderer(0, 0, 1600, 900);

  Line line(-0.5f, 0.3f, 0.5f, 0.0f, 0.01f);
  Circle circle(0.0f, 0.0f, 0.2f);

  while (!window.shouldClose()) {
    window.processInput();
    renderer.clear(0.1f, 0.5f, 0.1f, 1.0f);
    shader.use();

    // The correspoding VBO and EBO are automatically bound when VAO is bound.
    renderer.drawElements(line.getVAO(), 6);
    // renderer.drawElements(circle.getVAO(), circle.getVertices().size());
    window.swapBuffers();
    window.pollEvents();
  }
  return 0;
}
