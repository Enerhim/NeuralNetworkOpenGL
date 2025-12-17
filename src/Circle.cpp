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
  double angle = (360.0 / noSides) * (M_PI / 180.0);

  std::vector<float> vertices;

  // Center
  vertices.push_back(x1);
  vertices.push_back(y1);
  vertices.push_back(0);

  // First
  x1 += radius;

  for (size_t i = 0; i < noSides; i++) {
    float x_ = x1 * cos(angle) - y1 * sin(angle);
    float y_ = x1 * sin(angle) + y1 * cos(angle);

    x1 = x_;
    y1 = y_;
    vertices.push_back(x1);
    vertices.push_back(y1);
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
