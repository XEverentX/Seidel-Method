#include "../includes/statistic.hpp"
#include "../includes/utils.hpp"

#include <algorithm>
#include <cmath>

resultStatistics::resultStatistics(int n_n, int n_m) : n(n_n), m(n_m) {
    z = std::vector<std::vector<double>>(n, std::vector<double>(m));
    v = std::vector<std::vector<double>>(n, std::vector<double>(m));
    r = std::vector<std::vector<double>>(n, std::vector<double>(m));
    counter = 0;
    accuracy = 0.;
}

void resultStatistics::output() {
    std::cout << "\n/////////Results//////////\n\n";
    printMatrixInMarkDown(v);
    std::cout << "\n";
    std::cout << "Number of iterations: " << counter << "\n";
    std::cout << "Accuracy (x(s) - x(s - 1)): " << accuracy << "\n";
    std::cout << "Norm of Inaccuracy (x(s) - x): " << getInfinityVectorNorm(z) << "\n";
    std::cout << "Norm of discrepancy (A * z): " << getInfinityVectorNorm(r) << "\n";
    std::cout << "\n";
}

double resultStatistics::getInfinityVectorNorm(const std::vector<std::vector<double>> &vec) {
    double result = vec[0][0];
    for (auto x : vec) {
        for (auto y : x) {
            result = std::max(result, std::fabs(y));
        }
    }
    return result;
}

void resultStatistics::setInaccuracy(const std::vector<std::vector<double>> &realV) {
    int n = static_cast<int>(v.size());
    int m = static_cast<int>(v[0].size());
    z = std::vector<std::vector<double>>(n, std::vector<double>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            z[i][j] = v[i][j] - realV[i][j];
        }
    }
}

void resultStatistics::setDiscrepancy(const std::vector<std::vector<double>> &f,
                        const std::vector<std::vector<double>> &u,
                        double h,
                        double k) {
    int n = static_cast<int>(v.size());
    int m = static_cast<int>(v[0].size());

    int    dx[]   = {0, 1, 0, -1};
    int    dy[]   = {1, 0, -1, 0};
    double koef[] = {1. / (k * k), 1. / (h * h), 1. / (k * k), 1. / (h * h)};
    double a2 = -2. * (koef[0] + koef[1]);

    for (int j = 1; j < m - 1; j++) {
        for (int i = 1; i < n - 1; i++) {
            r[i][j] = z[i][j] * a2;
            for (int l = 0; l < 4; l++) {
                int ni = i + dx[l];
                int nj = j + dy[l];
                if (ni == 0 || ni == n - 1 || nj == 0 || nj == m - 1) {
                } else {
                    r[i][j] += z[ni][nj] * koef[l];
                }
            }
        }
    }
}
