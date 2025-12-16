#pragma once
#include <vector>
#include "Polygon.hpp"

class Circle : public Polygon {
public:
  Circle(float x1, float y1, float radius);

private:
  std::vector<float> C;
  std::vector<float> m_vertices;
  float radius;

  std::vector<float> calculateVertices(float x1, float y1, float radius);
  std::vector<unsigned int> calculateIndices();
};
