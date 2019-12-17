#pragma once

#include <vector>

double vectorNorm(const std::vector<double> &v);

std::vector<double> solveSeidel(std::vector<std::vector<double>> &a,
                                std::vector<double> &b,
                                double eps = 1e-8,
                                int approximationsCount = 500);