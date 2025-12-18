#pragma once
#include <vector>

std::vector<std::vector<double>> randomMatrix(size_t rows, size_t cols);
std::vector<double> randomVector(size_t size);

double dotProduct(std::vector<double> vecA, std::vector<double> vecB);
std::vector<double> dotProduct(std::vector<std::vector<double>> matA,
                               std::vector<double> vecB);
std::vector<std::vector<double>>
dotProduct(std::vector<std::vector<double>> matA,
           std::vector<std::vector<double>> matB);

std::vector<double> addVectors(std::vector<double> vecA,
                               std::vector<double> vecB);
std::vector<double> subtractVectors(std::vector<double> vecA,
                                    std::vector<double> vecB);
