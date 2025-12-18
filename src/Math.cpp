#include "Math.hpp"
#include <random>
#include <stdexcept>
#include <cmath>
#include <vector>

// Random

std::vector<std::vector<double>> randomMatrix(size_t rows, size_t cols) {
  std::random_device rd;
  std::mt19937 gen(rd());
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
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(-0.001, 0.001);

  std::vector<double> vec(size);
  for (size_t i = 0; i < size; i++) {
    vec[i] = dist(gen);
  }

  return std::vector<double>(size, 0.0);
}

// Matrix Vector Op

double dotProduct(std::vector<double> vecA, std::vector<double> vecB) {
  if (vecA.size() != vecB.size())
    throw std::runtime_error("Error: Wrong Sizes");

  double dot = 0;
  for (size_t i = 0; i < vecA.size(); i++) {
    dot += vecA[i] * vecB[i];
  }

  return dot;
}

std::vector<double> dotProduct(std::vector<std::vector<double>> matA,
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
dotProduct(std::vector<std::vector<double>> matA,
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

std::vector<double> addVectors(std::vector<double> vecA,
                               std::vector<double> vecB) {
  if (vecA.size() != vecB.size())
    throw std::runtime_error("Error: Wrong sizes");
  std::vector<double> vecC(vecA.size());
  for (size_t i = 0; i < vecA.size(); i++) {
    vecC[i] = vecA[i] + vecB[i];
  }

  return vecC;
}

// Activation Functions

double relu(double x) { return fmax(0, x); }

std::vector<double> reluV(std::vector<double> x) {
  std::vector<double> a(x.size());
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = relu(x[i]);
  }
  return a;
}

std::vector<std::vector<double>> relu(std::vector<std::vector<double>> x) {
  std::vector<std::vector<double>> a(x.size(),
                                     std::vector<double>(x[0].size()));
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = reluV(x[i]);
  }
  return a;
}

double linear(double x) { return x; }

std::vector<double> linearV(std::vector<double> x) {
  std::vector<double> a(x.size());
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = linear(x[i]);
  }
  return a;
}

std::vector<std::vector<double>> linear(std::vector<std::vector<double>> x) {
  std::vector<std::vector<double>> a(x.size(),
                                     std::vector<double>(x[0].size()));
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = linearV(x[i]);
  }
  return a;
}

double softmax(double x) { return 1; }

std::vector<double> softmaxV(std::vector<double> x) {
  std::vector<double> a(x.size());

  double max_val = x[0];
  for (double val : x)
    if (val > max_val)
      max_val = val;

  double esum = 0;
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = exp(x[i] - max_val);
    esum += exp(x[i]);
  }
  for (size_t i = 0; i < x.size(); i++) {
    a[i] /= esum;
  }
  return a;
}

std::vector<std::vector<double>> softmax(std::vector<std::vector<double>> x) {
  std::vector<std::vector<double>> a(x.size(),
                                     std::vector<double>(x[0].size()));
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = softmaxV(x[i]);
  }
  return a;
}

double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }

std::vector<double> sigmoidV(std::vector<double> x) {
  std::vector<double> a(x.size());
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = sigmoid(x[i]);
  }
  return a;
}

std::vector<std::vector<double>> sigmoid(std::vector<std::vector<double>> x) {
  std::vector<std::vector<double>> a(x.size(),
                                     std::vector<double>(x[0].size()));
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = sigmoidV(x[i]);
  }
  return a;
}

// Loss & Cost Function
double crossEntropyLoss(std::vector<double> a, unsigned int label) {
  return -log(a[label - 1]);
}

double costFuction(std::vector<std::vector<double>> examples,
                   std::vector<unsigned int> labels) {
  double sum = 0;
  for (size_t i = 0; i < examples.size(); i++) {
    sum += crossEntropyLoss(examples[i], labels[i]);
  }

  return sum / examples.size();
}
