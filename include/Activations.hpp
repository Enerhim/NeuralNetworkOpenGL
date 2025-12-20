#pragma once
#include <vector>

double relu(double x);
std::vector<double> reluV(const std::vector<double> &x);
std::vector<std::vector<double>>
relu(const std::vector<std::vector<double>> &x);

double linear(double x);
std::vector<double> linearV(const std::vector<double> &x);
std::vector<std::vector<double>>
linear(const std::vector<std::vector<double>> &x);

std::vector<double> softmaxV(const std::vector<double> &x);
std::vector<std::vector<double>>
softmax(const std::vector<std::vector<double>> &x);

double sigmoid(double x);
std::vector<double> sigmoidV(const std::vector<double> &x);
std::vector<std::vector<double>>
sigmoid(const std::vector<std::vector<double>> &x);
