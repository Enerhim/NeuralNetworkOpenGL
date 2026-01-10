#include "Random.hpp"
#include <random>

double randomNumber(double distStart, double distEnd) {
  static std::random_device rd;
  static std::mt19937 gen(rd());

  std::uniform_real_distribution<double> dist(distStart, distEnd);

  return dist(gen);
}

std::vector<std::vector<double>> randomMatrix(size_t rows, size_t cols) {
  // look up xavier/glorot random initialization
  std::vector<std::vector<double>> mat(rows, std::vector<double>(cols));

  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      mat[i][j] = randomNumber(-1.0 / sqrt(cols), 1.0 / sqrt(cols));
    }
  }

  return mat;
}

std::vector<double> randomVector(size_t size) {
  std::vector<double> vec(size);
  for (size_t i = 0; i < size; i++) {
    vec[i] = randomNumber(-0.001, 0.001);
  }

  return std::vector<double>(size, 0.0);
}
