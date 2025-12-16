#pragma once
#include <glad/glad.h>

class Shader {
public:
  Shader();
  ~Shader();

  void use() const;
  void setFloat(const char *name, float value) const;
  unsigned int id() const { return shaderProgram; }

private:
  unsigned int shaderProgram = 0;
  unsigned int compile(unsigned int type, const char *src);
};
