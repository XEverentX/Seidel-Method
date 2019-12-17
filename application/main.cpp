#include <iostream>
#include <cmath>

#include "./../algo/includes/difference_scheme.hpp"

int main() {
    int n = 4;
    int m = 4;

    int a = -1;
    int b = 1;
    int c = -1;
    int d = 1;

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

    auto v = solveDifferenceScheme(f, mu, a, b, c, d, n, m);

    // Printing of chain function
    auto printMatrix = [&] () -> void {
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                std::cout << v[i][j] << ' ';
            }
            std::cout << "\n";
        }    
    };

    auto printMatrixInMarkDown = [&] () -> void {
        std::cout << "| |";
        for (int i = 0; i < m + 1; i++) {
            std::cout << " y" << i << " |";
        }
        std::cout << "\n";

        for (int i = 0; i <= m + 1; i++) {
            std::cout << "|:---:";
        }
        std::cout << "|\n";

        for (int i = 0; i < n + 1; i++) {
            std::cout << "| x" << i;
            for (int j = 0; j < m + 1; j++) {
                std::cout << "| " << v[i][j] << " ";
            }
            std::cout << "|\n";
        }    
    };

    printMatrixInMarkDown();
    
    return 0;
}
