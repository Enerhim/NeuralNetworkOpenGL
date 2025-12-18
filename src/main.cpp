#include <glad/glad.h>
#include "Window.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "NeuralNetwork.hpp"
#include "Activations.hpp"

#include <iostream>

int main() {

  Window window(1600, 900, "nngl");
  Shader shader;
  Renderer renderer(0, 0, 1600, 900);

  Line line(-0.5f, 0.4f, 0.5f, 0.0f, 0.3f);
  Line line2(-0.7f, 0.0f, 0.2f, 0.5f, 0.05f);
  Circle circle(0.5f, 0.5f, 0.3f, (size_t)50);
  Circle circle2(0.2f, -0.4f, 0.1f, (size_t)10);

  NeuralNetwork network(5, {16, 16, 10}, {reluV, reluV, softmaxV});
  std::vector<double> a = network.inference({1, 1, 1, 1, 0.5});

  while (!window.shouldClose()) {
    window.processInput();
    renderer.clear(0.0f, 0.1f, 0.2f, 1.0f);
    shader.use();

    int width, height;
    window.getSizeByRef(width, height);

    float aspect = (height > 0) ? (float)width / height : 1.0f;
    shader.setFloat("u_aspect", aspect);

    renderer.drawElements(circle.getVAO(), circle.getIndices().size());
    renderer.drawElements(circle2.getVAO(), circle2.getIndices().size());
    renderer.drawElements(line.getVAO(), line.getIndices().size());
    renderer.drawElements(line2.getVAO(), line2.getIndices().size());
    window.swapBuffers();
    window.pollEvents();
  }
  return 0;
}
