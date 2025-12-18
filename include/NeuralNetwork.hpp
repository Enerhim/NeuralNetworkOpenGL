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
  void fit(std::vector<std::vector<double>> trainingData,
           std::vector<double> labels);

private:
  // Storing individual layer activations and z values for bp
  std::vector<std::vector<double>> m_aVals = {};
  std::vector<std::vector<double>> m_zVals = {};

  std::vector<std::vector<std::vector<double>>> m_weights = {};
  std::vector<std::vector<double>> m_biases = {};
  std::vector<size_t> m_units = {};
  std::vector<std::function<std::vector<double>(std::vector<double>)>>
      m_activations;
};
