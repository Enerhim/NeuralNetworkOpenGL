#pragma once
#include <vector>
#include "Polygon.hpp"

class Circle : public Polygon {
public:
  Circle(float x1, float y1, float radius, unsigned int noSides);

private:
  std::vector<float> C;
  std::vector<float> m_vertices;
  unsigned int m_noSides;
  float radius;

  std::vector<float> calculateVertices(float x1, float y1, float radius,
                                       unsigned int noSides);
  std::vector<unsigned int> calculateIndices(unsigned int noSides);
};
