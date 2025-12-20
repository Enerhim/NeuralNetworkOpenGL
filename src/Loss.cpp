#include "Loss.hpp"
#include <cmath>

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
