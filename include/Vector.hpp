#pragma once
#include <vector>

std::vector<std::vector<double>> randomMatrix(size_t rows, size_t cols);
std::vector<double> randomVector(size_t size);

double dotProduct(const std::vector<double> &vecA,
                  const std::vector<double> &vecB);
std::vector<double> dotProduct(const std::vector<std::vector<double>> &matA,
                               const std::vector<double> &vecB);
std::vector<std::vector<double>>
dotProduct(const std::vector<std::vector<double>> &matA,
           const std::vector<std::vector<double>> &matB);

std::vector<double> addVectors(const std::vector<double> &vecA,
                               const std::vector<double> &vecB,
                               std::vector<double> &result);
std::vector<double> subtractVectors(const std::vector<double> &vecA,
                                    const std::vector<double> &vecB,
                                    std::vector<double> &result);
