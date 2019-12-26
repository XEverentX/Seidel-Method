#pragma once

#include <vector>

void init(int argc, char** argv, 
          double &a, double &b, double &c, double &d, int &n, int &m, double &eps, int &maxCountApproximation);

void printMatrixInMarkDown(const std::vector<std::vector<double>> &v);

std::vector<std::vector<double>> buildA(int n, double h, double k);

std::vector<double> toVector(const std::vector<std::vector<double>> &v);

template<typename T> 
T sqr(T x) {
    return x * x;
}