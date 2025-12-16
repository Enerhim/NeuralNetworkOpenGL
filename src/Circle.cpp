#include "Circle.hpp"
#include <vector>
#include <cmath>
#include <iostream>

Circle::Circle(float x1, float y1, float radius)
    : Polygon(calculateVertices(x1, y1, radius), calculateIndices(),
              GL_STATIC_DRAW) {

  std::cout << "Successfully constructed" << std::endl;
}

std::vector<float> Circle::calculateVertices(float x1, float y1, float radius) {
  unsigned int noSides = 10;
  double angle = 360.0 / noSides;

  std::vector<float> vertices;

  // Center
  vertices.push_back(x1);
  vertices.push_back(y1);
  vertices.push_back(0);

  // First
  x1 += radius;

  for (int i = 0; i < noSides; i++) {
    float x_ = x1 * cos(angle) - y1 * sin(angle);
    float y_ = x1 * sin(angle) + y1 * cos(angle);

    x1 = x_;
    y1 = y_;
    std::cout << x1 << std::endl;
    vertices.push_back(x1);
    vertices.push_back(y1);
    vertices.push_back(0);
  }
  m_vertices = vertices;
  return vertices;
}

std::vector<unsigned int> Circle::calculateIndices() {
  unsigned int noSides = (m_vertices.size() / 3) - 1;
  std::vector<unsigned int> indices;

  for (int i = 0; i < noSides; i++) {
    indices.push_back(0);
    indices.push_back(i + 1);
    indices.push_back(i + 2);
  }

  return indices;
}
