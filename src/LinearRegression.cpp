#include "LinearRegression.hpp"
#include "Random.hpp"
#include <cmath>
#include "Vector.hpp"
#include <stdexcept>

LinearRegression::LinearRegression() {}

void LinearRegression::initWeights(size_t size) {
  m_weights = randomVector(size);
  // Xavier Glorot Initialization
  m_bias = randomNumber(-1.0 / sqrt(size), 1.0 / sqrt(size));
}

LinearRegression::~LinearRegression() {}

double LinearRegression::inference(std::vector<double> x) {
  return (dotProduct(x, m_weights) + m_bias);
}

std::vector<double>
LinearRegression::computeGradient(std::vector<std::vector<double>> X,
                                  std::vector<double> y) {
  std::vector<double> gradient(m_weights.size() + 1, 0);

  size_t m = X.size();
  size_t n = m_weights.size();

  for (size_t j = 0; j < n; j++) {
    for (size_t i = 0; i < m; i++) {
      gradient[j] += ((inference(X[i]) - y[i]) * X[i][j]);
    }
    gradient[j] /= m;
  }

  for (size_t i = 0; i < m; i++) {
    gradient[gradient.size() - 1] += (inference(X[i]) - y[i]);
  }
  gradient[gradient.size() - 1] /= m;

  return gradient;
}

void LinearRegression::fit(std::vector<std::vector<double>> X,
                           std::vector<double> y, double alpha, size_t epochs) {
  initWeights(X[0].size());

  if (X.size() != y.size()) {
    throw std::runtime_error("Error: Mismatch in training data");
  }

  for (size_t n = 0; n < epochs; n++) {

    std::vector<double> w_temp(m_weights.size(), 0);
    std::vector<double> gradient = computeGradient(X, y);

    for (size_t j = 0; j < m_weights.size(); j++) {
      w_temp[j] = m_weights[j] - alpha * gradient[j];
    }

    double b_ = m_bias - alpha * gradient[gradient.size() - 1];

    for (size_t j = 0; j < m_weights.size(); j++) {
      m_weights[j] = w_temp[j];
    }
    m_bias = b_;
  }
}
