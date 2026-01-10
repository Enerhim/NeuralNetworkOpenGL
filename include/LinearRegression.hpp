#pragma once
#include <vector>

class LinearRegression {
public:
  LinearRegression();
  ~LinearRegression();

  double inference(std::vector<double> X);
  void fit(std::vector<std::vector<double>> X, std::vector<double> y,
           double alpha = 0.001, size_t epochs = 10);

  std::vector<double> getWeights() const { return m_weights; }
  double getBias() const { return m_bias; }
  size_t noParameters() const { return (m_weights.size() + 1); }

private:
  std::vector<double> m_weights;
  float m_bias;
  void initWeights(size_t size);

  std::vector<double> computeGradient(std::vector<std::vector<double>> X,
                                      std::vector<double> y);
};
