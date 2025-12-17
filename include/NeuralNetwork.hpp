#pragma once
#include <functional>
#include <vector>

class NeuralNetwork {
public:
  NeuralNetwork(
      int inputSize, std::vector<size_t> units,
      std::vector<std::function<std::vector<double>(std::vector<double>)>>
          activations);

  std::vector<double> inference(std::vector<double> inputVector);

private:
  std::vector<std::vector<std::vector<double>>> m_weights = {};
  std::vector<std::vector<double>> m_biases = {};
  std::vector<size_t> m_units;
  std::vector<std::function<std::vector<double>(std::vector<double>)>>
      m_activations;
};
