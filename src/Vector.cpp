#include "Vector.hpp"
#include <stdexcept>

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
