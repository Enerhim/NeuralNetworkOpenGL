#include "NeuralNetwork.hpp"
#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>

NeuralNetwork::NeuralNetwork(int inputSize, std::vector<size_t> units,
                             std::vector<const char *> activations) {
  m_units = units;
  // Initialize weights and biases.
  m_weights.push_back(randomMatrix(m_units[0], inputSize));
  for (size_t i = 0; i < m_units.size(); i++) {
    m_biases.push_back(randomVector(m_units[i]));
    if (i == 0)
      continue;
    m_weights.push_back(randomMatrix(m_units[i], m_units[i - 1]));
  }
};

std::vector<std::vector<double>> NeuralNetwork::randomMatrix(size_t rows,
                                                             size_t cols) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(0, 1);
  std::vector<std::vector<double>> mat(rows, std::vector<double>(cols));

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      mat[i][j] = dist(gen);
    }
  }

  return mat;
}

std::vector<double> NeuralNetwork::randomVector(size_t size) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(0, 1);

  std::vector<double> vec(size);
  for (size_t i = 0; i < size; i++) {
    vec[i] = dist(gen);
  }

  return vec;
}

std::vector<double> NeuralNetwork::inference(std::vector<double> inputVector) {
  std::vector<double> a;
  for (size_t i = 0; i < m_units.size(); i++) {
    std::vector<double> z =
        addVectors(dotProduct(m_weights[i], inputVector), m_biases[i]);
    std::cout << z[0];
  }

  return {};
}

double NeuralNetwork::dotProduct(std::vector<double> vecA,
                                 std::vector<double> vecB) {
  if (vecA.size() != vecB.size())
    throw std::runtime_error("Error: Wrong Sizes");

  double dot;
  for (size_t i = 0; i < vecA.size(); i++) {
    dot += vecA[i] * vecB[i];
  }

  return dot;
}

std::vector<double>
NeuralNetwork::dotProduct(std::vector<std::vector<double>> matA,
                          std::vector<double> vecB) {
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
NeuralNetwork::dotProduct(std::vector<std::vector<double>> matA,
                          std::vector<std::vector<double>> matB) {

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

std::vector<double> NeuralNetwork::addVectors(std::vector<double> vecA,
                                              std::vector<double> vecB) {
  if (vecA.size() != vecB.size())
    throw std::runtime_error("Error: Wrong sizes");
  std::vector<double> vecC;
  for (size_t i = 0; i < vecA.size(); i++) {
    vecC[i] = vecA[i] + vecB[i];
  }

  return vecC;
}
