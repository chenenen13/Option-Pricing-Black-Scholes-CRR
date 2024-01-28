#pragma once
#include <random>

class MT {
public:
    MT();
    static MT& getInstance();
    static double rand_unif();
    static double rand_norm();
private:

    std::mt19937 generator;
    std::uniform_real_distribution<double> distribution_unif{ 0.0, 1.0 };
    std::normal_distribution<double> distribution_norm{ 0.0, 1.0 };
};