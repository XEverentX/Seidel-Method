#pragma once

#include <vector>
#include <functional>

template<typename T> 
T sqr(T x) {
    return x * x;
}

std::vector<std::vector<double>> solveDifferenceScheme(std::function<double(double, double)> f,
                                                       std::function<double(double)> mu[],
                                                       double a,
                                                       double b,
                                                       double c,
                                                       double d,
                                                       int n,
                                                       int m,
                                                       double eps = 0.0000001,
                                                       int maxCountApproximation = 10000);

std::vector<std::vector<double>> getUMatrix(std::function<double(double, double)> u,
                                            double a,
                                            double b,
                                            double c,
                                            double d,
                                            int n,
                                            int m);                                                      
