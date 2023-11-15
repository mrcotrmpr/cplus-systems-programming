#include "include/random_generator.hpp"

int RandomGenerator::generate_random_int(int lower, int upper) {
    std::uniform_int_distribution<int> dist(lower, upper);
    return dist(engine);
}

double RandomGenerator::generate_random_double(double lower, double upper) {
    std::uniform_real_distribution<double> dist(lower, upper);
    return dist(engine);
}

double RandomGenerator::generate_double_zero_to_one() {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(engine);
}

bool RandomGenerator::generate_random_bool() {
    std::uniform_int_distribution<int> dist(0, 1);
    return dist(engine) == 1;
}
