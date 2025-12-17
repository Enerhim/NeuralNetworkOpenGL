#include "Circle.hpp"
#include <vector>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circle::Circle(float x1, float y1, float radius, size_t noSides)
    : Polygon(calculateVertices(x1, y1, radius, noSides),
              calculateIndices(noSides), GL_STATIC_DRAW) {
  m_noSides = noSides;
}

std::vector<float> Circle::calculateVertices(float x1, float y1, float radius,
                                             size_t noSides) {
  double angle = (2.0 * M_PI) / noSides;

  std::vector<float> vertices;

  // Center
  vertices.push_back(x1);
  vertices.push_back(y1);
  vertices.push_back(0);

  for (size_t i = 0; i < noSides; i++) {
    vertices.push_back(x1 + radius * cos(i * angle));
    vertices.push_back(y1 + radius * sin(i * angle));
    vertices.push_back(0);
  }
  return vertices;
}

std::vector<unsigned int> Circle::calculateIndices(size_t noSides) {
  std::vector<unsigned int> indices;

  for (size_t i = 0; i < noSides; i++) {
    indices.push_back(0);
    indices.push_back(i + 1);

    if (i == noSides - 1) {
      indices.push_back(1);
    } else
      indices.push_back(i + 2);
  }

  return indices;
}
