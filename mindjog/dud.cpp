#include <random>
#include <iostream>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(0.5);

    bool gee = d(gen);
    std::cout << gee;
    return 0;
}
