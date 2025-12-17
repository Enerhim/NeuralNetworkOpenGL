#pragma once
#include <vector>

class NeuralNetwork {
public:
  NeuralNetwork(int inputSize, std::vector<size_t> units,
                std::vector<const char *> activations);

  std::vector<double> inference(std::vector<double> inputVector);

private:
  std::vector<std::vector<std::vector<double>>> m_weights = {};
  std::vector<std::vector<double>> m_biases = {};
  std::vector<size_t> m_units;

  std::vector<std::vector<double>> randomMatrix(size_t rows, size_t cols);
  std::vector<double> randomVector(size_t size);

  // Helper Functions
  double dotProduct(std::vector<double> vecA, std::vector<double> vecB);
  std::vector<double> dotProduct(std::vector<std::vector<double>> matA,
                                 std::vector<double> vecB);
  std::vector<std::vector<double>>
  dotProduct(std::vector<std::vector<double>> matA,
             std::vector<std::vector<double>> matB);

  std::vector<double> addVectors(std::vector<double> vecA,
                                 std::vector<double> vecB);
};
