#include <glad/glad.h>
#include "Window.hpp"
#include "Shader.hpp"
#include "Renderer.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "NeuralNetwork.hpp"
#include "Math.hpp"

#include <iostream>

int main() {

  Window window(1600, 900, "nngl");
  Shader shader;
  Renderer renderer(0, 0, 1600, 900);

  Line line(-0.5f, 0.3f, 0.5f, 0.0f, 0.01f);
  Circle circle(0.7f, 0.0f, 0.6f, 200);

  NeuralNetwork network(16, {16, 16, 10}, {reluV, reluV, softmaxV});
  std::vector<double> a = network.inference(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});

  for (size_t i = 0; i < 10; i++)
    std::cout << a[i] << std::endl;

  while (!window.shouldClose()) {
    window.processInput();
    renderer.clear(0.1f, 0.5f, 0.1f, 1.0f);
    shader.use();

    int width, height;
    window.getSizeByRef(width, height);

    float aspect = (height > 0) ? (float)width / height : 1.0f;
    shader.setFloat("u_aspect", aspect);

    renderer.drawElements(line.getVAO(), 6);
    renderer.drawElements(circle.getVAO(), circle.getIndices().size());
    window.swapBuffers();
    window.pollEvents();
  }
  return 0;
}
