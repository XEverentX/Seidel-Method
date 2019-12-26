#pragma once

#include <iostream>
#include <vector>

struct resultStatistics {
    int                              n;
    int                              m;
    int                              counter;
    double                           accuracy;
    std::vector<std::vector<double>> z;
    std::vector<std::vector<double>> v;
    std::vector<std::vector<double>> r;

    resultStatistics() = default;

    resultStatistics(int n_n, int n_m);
    
    double getInfinityVectorNorm(const std::vector<std::vector<double>> &vec);

    void setInaccuracy(const std::vector<std::vector<double>> &realV);

    void setDiscrepancy(const std::vector<std::vector<double>> &f,
                        const std::vector<std::vector<double>> &u,
                        double h,
                        double k);
                        

    void output();
};
