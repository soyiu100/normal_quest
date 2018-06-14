#include <random>

namespace randDevice {
    std::random_device rd;
    std::mt19937 gen(rd());
};
using namespace randDevice;

// @requires : 0 <= trueBias <= 1
// @param    : trueBias
bool randBool(float trueBias) {
    std::bernoulli_distribution dist(trueBias);
    return dist(gen);
}

int randInt(int upperBound) {
    std::uniform_int_distribution<> rng(0, upperBound);
    return rng(gen);
}
