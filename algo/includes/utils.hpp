#pragma once

#include <vector>

void init(int argc, char** argv, 
          double &a, double &b, double &c, double &d, int &n, int &m, double &eps, int &maxCountApproximation);

void printMatrixInMarkDown(const std::vector<std::vector<double>> &v);