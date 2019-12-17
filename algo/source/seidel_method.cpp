#include <cmath>

#include "./../includes/seidel_method.hpp"

double vectorNorm(const std::vector<double> &v) {
    double result = 0.0;
    for (auto x : v) {
        result += x * x;
    }
    return std::sqrt(result);
}

std::vector<double> solveSeidel(std::vector<std::vector<double>> &a,
                                std::vector<double> &b,
                                double eps,
                                int approximationsCount) {
    int n = static_cast<int>(b.size());

    std::vector<double> x(n);
    std::vector<double> oldX(n, 0);

    do {
        for (int i = 0; i < n; i++) {
            double currentSum = b[i];

            for (int j = 0; j < i; j++) {
                currentSum -= a[i][j] * x[j];
            }

            for (int j = i + 1; j < n; j++) {
                currentSum -= a[i][j] * x[j];
            }

            oldX[i] = x[i];
            x[i] = currentSum / a[i][i];
        }
    } while (std::fabs(vectorNorm(x) - vectorNorm(oldX)) >= eps && approximationsCount--);

    return x;
}