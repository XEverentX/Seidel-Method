#include <vector>
#include <cmath>
#include <iostream>

#include "../includes/difference_scheme.hpp"

// Due to the sparse of matrix it's incorrect to use classic Seidel so this function implemet it
std::vector<std::vector<double>> solveDifferenceScheme(std::function<double(double, double)> f,
                                                       std::function<double(double)> mu[4],
                                                       double a,
                                                       double b,
                                                       double c,
                                                       double d,
                                                       int n,
                                                       int m,
                                                       double eps,
                                                       int maxCountApproximation)
{
    double h      = static_cast<double>(b - a) / static_cast<double>(n);
    double k      = static_cast<double>(d - c) /static_cast<double>(m);
    double h2     = -1 / sqr(h);
    double k2     = -1 / sqr(k);
    double a2      = -2 * (h2 + k2);
    double maxEps = 0.;
    int    counter = 0;

    std::vector<std::vector<double>> v(n + 1, std::vector<double>(m + 1));

    auto getX = [&] (int i) -> double {
        return a + h * i;
    };

    auto getY = [&] (int j) -> double {
        return c + k * j;
    };
    
    // Init v on the bord
    for (int i = 0; i < n + 1; i++) {
        v[i][0] = mu[3](getX(i));
        v[i][m] = mu[4](getX(i));   
    }
    for (int j = 0; j < m + 1; j++) {
        v[0][j] = mu[1](getY(j));
        v[n][j] = mu[2](getY(j));
    }

    // Seidel Implemetation
    do {
        maxEps = 0.;
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                double oldV = v[i][j];
                v[i][j] = -(h2 * (v[i + 1][j] + v[i - 1][j]) + k2 * (v[i][j + 1] + v[i][j - 1]));
                v[i][j] += f(getX(i), getY(j));
                v[i][j] /= a2;
                double currEps = std::fabs(oldV - v[i][j]);
                if (currEps > maxEps) {
                    maxEps = currEps;
                }
            }
        }
        counter++;
    } while(maxEps >= eps && counter < maxCountApproximation);

    std::cout << "\nResults:\n";
    std::cout << "NumOfApproximations: " << counter << std::endl;
    std::cout << "Result epsilon: " << maxEps << std::endl;
    return v;
}

std::vector<std::vector<double>> getUMatrix(std::function<double(double, double)> u,
                                            double a,
                                            double b,
                                            double c,
                                            double d,
                                            int n,
                                            int m) 
{
    std::vector<std::vector<double>> v(n + 1, std::vector<double>(m + 1));

    double h = static_cast<double>(b - a) / static_cast<double>(n);
    double k = static_cast<double>(d - c) /static_cast<double>(m);

    auto getX = [&] (int i) -> double {
        return a + h * i;
    };

    auto getY = [&] (int j) -> double {
        return c + k * j;
    };

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            v[i][j] = u(getX(i), getY(j));    
        }
    }
    return v;
}
