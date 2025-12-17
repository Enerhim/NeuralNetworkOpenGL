#include "NeuralNetwork.hpp"
#include <vector>
#include "Math.hpp"

NeuralNetwork::NeuralNetwork(
    int inputSize, std::vector<size_t> units,
    std::vector<std::function<std::vector<double>(std::vector<double>)>>
        activations) {
  m_units = units;
  m_activations = activations;
  // Initialize weights and biases.
  m_weights.push_back(randomMatrix(m_units[0], inputSize));
  for (size_t i = 0; i < m_units.size(); i++) {
    m_biases.push_back(randomVector(m_units[i]));
    if (i == 0)
      continue;
    m_weights.push_back(randomMatrix(m_units[i], m_units[i - 1]));
  }
};

std::vector<double> NeuralNetwork::inference(std::vector<double> inputVector) {
  std::vector<double> a = inputVector;
  for (size_t i = 0; i < m_units.size(); i++) {
    a = m_activations[i](addVectors(dotProduct(m_weights[i], a), m_biases[i]));
  }

  return a;
}
