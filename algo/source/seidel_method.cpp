#include <cmath>

#include "./../includes/seidel_method.h"

double vectorNorm(const std::vector<double> &v) {
    double result = 0.0;
    for (auto x : v) {
        result += x * x;
    }
    return std::sqrt(result);
}

std::vector<double> solveSequentialSeidel(std::vector<std::vector<double>> &a,
                                          std::vector<double> &b,
                                          double eps,
                                          int approximationsCount) {
    size_t              n = b.size();
    std::vector<double> x(n);
    std::vector<double> oldX(n, 0);

    do {
        for (size_t i = 0; i < n; i++) {
            double currentSum = b[i];

            for (size_t j = 0; j < i; j++) {
                currentSum -= a[i][j] * x[j];
            }

            for (size_t j = i + 1; j < n; j++) {
                currentSum -= a[i][j] * x[j];
            }

            oldX[i] = x[i];
            x[i] = currentSum / a[i][i];
        }
    } while (std::fabs(vectorNorm(x) - vectorNorm(oldX)) >= eps && approximationsCount--);

    return x;
}