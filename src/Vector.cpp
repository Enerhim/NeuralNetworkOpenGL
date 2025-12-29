#include "Vector.hpp"
#include <stdexcept>
#include <random>

std::vector<std::vector<double>> randomMatrix(size_t rows, size_t cols) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  // look up xavier/glorot random initialization
  std::uniform_real_distribution<double> dist(-1.0 / sqrt(cols),
                                              1.0 / sqrt(cols));
  std::vector<std::vector<double>> mat(rows, std::vector<double>(cols));

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      mat[i][j] = dist(gen);
    }
  }

  return mat;
}

std::vector<double> randomVector(size_t size) {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(-0.001, 0.001);

  std::vector<double> vec(size);
  for (size_t i = 0; i < size; i++) {
    vec[i] = dist(gen);
  }

  return std::vector<double>(size, 0.0);
}

// Matrix Vector Op

double dotProduct(const std::vector<double> &vecA,
                  const std::vector<double> &vecB) {
  if (vecA.size() != vecB.size())
    throw std::runtime_error("Error: Wrong Sizes");

  double dot = 0;
  for (size_t i = 0; i < vecA.size(); i++) {
    dot += vecA[i] * vecB[i];
  }

  return dot;
}

std::vector<double> dotProduct(const std::vector<std::vector<double>> &matA,
                               const std::vector<double> &vecB) {
  if (matA.empty() || matA[0].size() != vecB.size())
    throw std::runtime_error("Error: Wrong Sizes");

  std::vector<double> dot(matA.size(), 0.0);
  for (size_t i = 0; i < matA.size(); i++) {
    if (matA[i].size() != vecB.size())
      throw std::runtime_error("Error: Inconsistent row size in matrix");
    for (size_t j = 0; j < vecB.size(); j++) {
      dot[i] += matA[i][j] * vecB[j];
    }
  }
  return dot;
}

std::vector<std::vector<double>>
dotProduct(const std::vector<std::vector<double>> &matA,
           const std::vector<std::vector<double>> &matB) {

  if (matA.empty() || matA[0].size() != matB.size())
    throw std::runtime_error("Error: Wrong sizes");
  std::vector<std::vector<double>> dot(matA.size(),
                                       std::vector<double>(matB[0].size()));

  for (size_t k = 0; k < matB[0].size(); k++) {
    for (size_t i = 0; i < matA.size(); i++) {
      if (matA[i].size() != matB.size())
        throw std::runtime_error("Error: Inconsistent row size in matrix");
      for (size_t j = 0; j < matB.size(); j++) {
        dot[i][k] += matA[i][j] * matB[j][k];
      }
    }
  }

  return dot;
}

std::vector<double> addVectors(const std::vector<double> &vecA,
                               const std::vector<double> &vecB,
                               std::vector<double> &vecC) {
  if (vecA.size() != vecB.size())
    throw std::runtime_error("Error: Wrong sizes");
  if (vecC.size() != vecA.size())
    vecC.resize(vecA.size());
  for (size_t i = 0; i < vecA.size(); i++) {
    vecC[i] = vecA[i] + vecB[i];
  }

  return vecC;
}

std::vector<double> subtractVectors(const std::vector<double> &vecA,
                                    const std::vector<double> &vecB,
                                    std::vector<double> &vecC) {
  if (vecA.size() != vecB.size())
    throw std::runtime_error("Error: Wrong sizes");
  if (vecC.size() != vecA.size())
    vecC.resize(vecA.size());
  for (size_t i = 0; i < vecA.size(); i++) {
    vecC[i] = vecA[i] - vecB[i];
  }

  return vecC;
}
