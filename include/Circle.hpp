#pragma once
#include <vector>
#include "Polygon.hpp"

class Circle : public Polygon {
public:
  Circle(float x1, float y1, float radius, size_t noSides);

private:
  std::vector<float> C;
  size_t m_noSides;
  float radius;

  std::vector<float> calculateVertices(float x1, float y1, float radius,
                                       size_t noSides);
  std::vector<unsigned int> calculateIndices(size_t noSides);
};
