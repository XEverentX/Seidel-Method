#include <vector>
#include <cmath>
#include <iostream>

#include "../includes/difference_scheme.hpp"
#include "../includes/utils.hpp"

// Due to the sparse of matrix it's incorrect to use classic Seidel so this function implemet it
resultStatistics solveDifferenceScheme(std::function<double(double, double)> f,
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
    double h      = (b - a) / n;
    double k      = (d - c) / m;
    double h2     = -1 / sqr(h);
    double k2     = -1 / sqr(k);
    double a2     = -2 * (h2 + k2);
    double maxEps = 0.;

    resultStatistics res(n + 1, m + 1);

    auto getX = [&] (int i) -> double {
        return a + h * i;
    };

    auto getY = [&] (int j) -> double {
        return c + k * j;
    };
    
    // Init v on the bord
    for (int i = 0; i < n + 1; i++) {
        res.v[i][0] = mu[3](getX(i));
        res.v[i][m] = mu[4](getX(i));   
    }
    for (int j = 0; j < m + 1; j++) {
        res.v[0][j] = mu[1](getY(j));
        res.v[n][j] = mu[2](getY(j));
    }

    // Seidel Implemetation
    do {
        maxEps = 0.;
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                double oldV = res.v[i][j];
                res.v[i][j] = -(h2 * (res.v[i + 1][j] + res.v[i - 1][j]) + k2 * (res.v[i][j + 1] + res.v[i][j - 1]));
                res.v[i][j] += f(getX(i), getY(j));
                res.v[i][j] /= a2;
                double currEps = std::fabs(oldV - res.v[i][j]);
                if (currEps > maxEps) {
                    maxEps = currEps;
                }
            }
        }
        res.counter++;
    } while(maxEps >= eps && res.counter < maxCountApproximation);
    res.accuracy = maxEps;

    return res;
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

    double h = (b - a) / n;
    double k = (d - c) / m;

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
