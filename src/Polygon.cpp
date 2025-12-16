#include "Polygon.hpp"

Polygon::Polygon(std::vector<float> vertices, std::vector<unsigned int> indices,
                 GLenum drawMode) {
  m_vertices = vertices;
  m_indices = indices;

  glGenBuffers(1, &m_VBO);
  glGenBuffers(1, &m_EBO);
  glGenVertexArrays(1, &m_VAO);

  glBindVertexArray(m_VAO);
  glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);

  glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float),
               m_vertices.data(), drawMode);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int),
               m_indices.data(), drawMode);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glBindVertexArray(0);
}

Polygon::~Polygon() {
  if (m_VBO != 0) {
    glDeleteBuffers(1, &m_VBO);
  }
  if (m_EBO != 0) {
    glDeleteBuffers(1, &m_EBO);
  }
  if (m_VAO != 0) {
    glDeleteVertexArrays(1, &m_VAO);
  }
}
