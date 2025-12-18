#pragma once
#include <vector>

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
