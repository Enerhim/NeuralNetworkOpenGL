#pragma once
#include <glad/glad.h>
#include <vector>

class Polygon {
public:
  Polygon(std::vector<float> vertices, std::vector<unsigned int> indices,
          GLenum drawMode = GL_STATIC_DRAW);
  ~Polygon();

  unsigned int getVAO() const { return m_VAO; }
  std::vector<float> getVertices() const { return m_vertices; }
  std::vector<unsigned int> getIndices() const { return m_indices; }

private:
  std::vector<float> m_vertices;
  std::vector<unsigned int> m_indices;
  unsigned int m_VAO, m_VBO, m_EBO;
};
