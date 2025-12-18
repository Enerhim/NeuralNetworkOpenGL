#pragma once
#include <vector>

double crossEntropyLoss(std::vector<double> a, unsigned int y);
double costFuction(std::vector<std::vector<double>> examples,
                   std::vector<unsigned int> labels);
