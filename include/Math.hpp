#pragma once
#include <vector>

// Random
std::vector<std::vector<double>> randomMatrix(size_t rows, size_t cols);
std::vector<double> randomVector(size_t size);

// Vector - Matrix Op

double dotProduct(std::vector<double> vecA, std::vector<double> vecB);
std::vector<double> dotProduct(std::vector<std::vector<double>> matA,
                               std::vector<double> vecB);
std::vector<std::vector<double>>
dotProduct(std::vector<std::vector<double>> matA,
           std::vector<std::vector<double>> matB);

std::vector<double> addVectors(std::vector<double> vecA,
                               std::vector<double> vecB);

// Activations
double relu(double x);
std::vector<double> reluV(std::vector<double> x);
std::vector<std::vector<double>> relu(std::vector<std::vector<double>> x);

double linear(double x);
std::vector<double> linearV(std::vector<double> x);
std::vector<std::vector<double>> linear(std::vector<std::vector<double>> x);

double softmax(double x);
std::vector<double> softmaxV(std::vector<double> x);
std::vector<std::vector<double>> softmax(std::vector<std::vector<double>> x);

double sigmoid(double x);
std::vector<double> sigmoidV(std::vector<double> x);
std::vector<std::vector<double>> sigmoid(std::vector<std::vector<double>> x);

// Loss & Cost Function
double crossEntropyLoss(std::vector<double> a, unsigned int y);
double costFuction(std::vector<std::vector<double>> examples,
                   std::vector<unsigned int> labels);
