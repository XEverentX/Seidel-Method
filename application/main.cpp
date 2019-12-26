#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

#include "./../algo/includes/difference_scheme.hpp"
#include "./../algo/includes/utils.hpp"

int main(int argc, char** argv) {
    int    n                     = 4;
    int    m                     = 4;
    int    maxApproximationCount = 100000;
    double a                     = -1;
    double b                     = 1;
    double c                     = -1;
    double d                     = 1;
    double eps                   = 0.0000001;    

    init(argc, argv, a, b, c, d, n, m, eps, maxApproximationCount);    

    auto u = [] (double x, double y) -> double {
        return 1 - sqr(x) - sqr(y);
    };

    std::function<double(double)> mu[5];

    mu[1] = [] (double y) -> double {
        return -sqr(y);
    };

    mu[2] = [] (double y) -> double {
        return -sqr(y);
    };

    mu[3] = [] (double x) -> double {
        return -sqr(x);
    };

    mu[4] = [] (double x) -> double {
        return -sqr(x);
    };

    auto f = [] (double x, double y) -> double {
        return 4.;    
    };

    auto res = solveDifferenceScheme(f, mu, a, b, c, d, n, m, eps, maxApproximationCount);
    res.setInaccuracy(getUMatrix(u, a, b, c, d, n, m));
    res.setDiscrepancy(getUMatrix(f, a, b, c, d, n, m), getUMatrix(u, a, b, c, d, n, m), (b - a) / n, (d - c) / m);

    res.output();

    return 0;
}
