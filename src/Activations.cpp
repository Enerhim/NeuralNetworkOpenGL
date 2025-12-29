#include "Activations.hpp"
#include <cmath>

// Relu
double relu(double x) { return fmax(0, x); }

std::vector<double> reluV(const std::vector<double> &x) {
  std::vector<double> a(x.size());
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = relu(x[i]);
  }
  return a;
}

std::vector<std::vector<double>>
relu(const std::vector<std::vector<double>> &x) {
  std::vector<std::vector<double>> a(x.size(),
                                     std::vector<double>(x[0].size()));
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = reluV(x[i]);
  }
  return a;
}

// Linear

double linear(double x) { return x; }

std::vector<double> linearV(const std::vector<double> &x) {
  std::vector<double> a(x.size());
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = linear(x[i]);
  }
  return a;
}

std::vector<std::vector<double>>
linear(const std::vector<std::vector<double>> &x) {
  std::vector<std::vector<double>> a(x.size(),
                                     std::vector<double>(x[0].size()));
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = linearV(x[i]);
  }
  return a;
}

// Softmax

std::vector<double> softmaxV(const std::vector<double> &x) {
  std::vector<double> a(x.size());

  double max_val = x[0];
  for (double val : x)
    if (val > max_val)
      max_val = val;

  double esum = 0;
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = exp(x[i] - max_val);
    esum += a[i];
  }
  for (size_t i = 0; i < x.size(); i++) {
    a[i] /= esum;
  }
  return a;
}

std::vector<std::vector<double>>
softmax(const std::vector<std::vector<double>> &x) {
  std::vector<std::vector<double>> a(x.size(),
                                     std::vector<double>(x[0].size()));
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = softmaxV(x[i]);
  }
  return a;
}

// Sigmoid

double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }

std::vector<double> sigmoidV(const std::vector<double> &x) {
  std::vector<double> a(x.size());
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = sigmoid(x[i]);
  }
  return a;
}

std::vector<std::vector<double>>
sigmoid(const std::vector<std::vector<double>> &x) {
  std::vector<std::vector<double>> a(x.size(),
                                     std::vector<double>(x[0].size()));
  for (size_t i = 0; i < x.size(); i++) {
    a[i] = sigmoidV(x[i]);
  }
  return a;
}
