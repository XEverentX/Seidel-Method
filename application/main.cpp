#include <iostream>

#include "./../algo/includes/seidel_method.h"

int main() {
    size_t n = 3;

    std::vector<std::vector<double>> a(n, std::vector<double>(n));

    a[0][0] = 10; a[0][1] = 1; a[0][2] = 1;
    a[1][0] = 2; a[1][1] = 10; a[1][2] = 1;
    a[2][0] = 2; a[2][1] = 2; a[2][2] = 10;

    std::vector<double> b(n);
    b[0] = 12; b[1] = 13; b[2] = 14;

    double eps = 0.00001;
    bool bad = false;

    std::vector<double> expectedVector(n, 1.);
    auto result = solveSeidel(a, b);
    for (size_t i = 0; i < n; i++) {
        if (abs(expectedVector[i] - result[i]) >= eps) bad = true;
    }
    std::cout << (bad ? "Problems there" : "It's Okay") << std::endl;
}
