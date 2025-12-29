#include "NeuralNetwork.hpp"
#include "Vector.hpp"

NeuralNetwork::NeuralNetwork(
    int inputSize, std::vector<size_t> units,
    std::vector<std::function<std::vector<double>(std::vector<double>)>>
        activations) {
  m_units = units;
  m_activations = activations;

  m_aVals.resize(m_units.size() + 1);
  m_zVals.resize(m_units.size());

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
  m_aVals[0] = inputVector;

  std::vector<double> a = inputVector;

  for (size_t i = 0; i < m_units.size(); i++) {
    addVectors(dotProduct(m_weights[i], a), m_biases[i], m_zVals[i]);
    a = m_activations[i](m_zVals[i]);

    m_aVals[i + 1] = a;
  }

  return a;
}

void NeuralNetwork::fit(std::vector<std::vector<double>> trainingData,
                        std::vector<double> labels) {
  for (size_t l = m_units.size(); l > 0; l--) {
    for (size_t i = 0; i < m_weights[l].size(); i++) {
      for (size_t j = 0; j < m_weights[l][i].size(); j++) {
        // Todo
        // Implement Gradient Descent & Backprop
      }
    }
  }
}
