#include "./../includes/utils.hpp"
#include <string>
#include <iostream>

void init(int argc, char** argv, 
          double &a, double &b, double &c, double &d, int &n, int &m, double &eps, int &maxCountApproximation) {
    n                     = 4;
    m                     = 4;
    a                     = -1;
    b                     = 1;
    c                     = -1;
    d                     = 1;
    maxCountApproximation = 100000;
    eps                   = 0.0000001;


    for (int i = 1; i < argc; i += 2) {
        switch (argv[i][1])
        {
        case 'n':
            n = std::stoi(argv[i + 1]);
            break;

        case 'm':
            m = std::stoi(argv[i + 1]);
            break;

        case 'a':
            a = std::stold(argv[i + 1]);
            break;

        case 'b':
            b = std::stold(argv[i + 1]);
            break;

        case 'c':
            c = std::stold(argv[i + 1]);
            break;

        case 'd':
            d = std::stold(argv[i + 1]);
            break;

        case 'l':
            maxCountApproximation = std::stoi(argv[i + 1]);
            break;
        
        case 'e':
            eps = std::stold(argv[i + 1]);
            break;
        
        default:
            break;
        }        
    } 
    std::cout << "Parametrs:\n";
    std::cout << "n = " << n << std::endl;
    std::cout << "m = " << m << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "presicion = " << eps << std::endl;
    std::cout << "Approximations boundery = " << maxCountApproximation << std::endl;
}

void printByCount(int cnt, char x = ' ') {
    for(int i = 0; i < 7 - cnt; i++) std::cout << x;
}

void printMatrixInMarkDown(const std::vector<std::vector<double>> &v) {
    int n = static_cast<int>(v.size()) - 1;
    int m = static_cast<int>(v[0].size()) - 1;

    std::cout << "|";
    printByCount(0);
    std::cout << "|";
    for (int i = 0; i < n + 1; i++) {
        printByCount(2);
        std::cout << "x" << i << "|";
    }
    std::cout << "\n";

    for (int i = 0; i <= n + 1; i++) {
        std::cout << "|:";
        printByCount(2, '-');
        std::cout << ":";
    }
    std::cout << "|\n";

    for (int i = 0; i < m + 1; i++) {
        std::cout << "|";
        printByCount(2);
        std::cout << "y" << m - i;
        for (int j = 0; j < n + 1; j++) {
            std::cout << "|";
            printByCount(5 + (v[j][m - i] <= 0. ? 1 : 0));
            printf("%.3lf", v[j][m - i]);
        }
        std::cout << "|\n";
    }    
}