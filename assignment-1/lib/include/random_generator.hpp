#ifndef RANDOM_GENERATOR_HPP
#define RANDOM_GENERATOR_HPP

#include "include/random_engine_manager.hpp"

class RandomGenerator {
public:
    int generate_random_int(int lower, int upper);
    double generate_random_double(double lower, double upper);
    double generate_double_zero_to_one();
    bool generate_random_bool();

    template <typename T>
    T choose_random_item(const std::vector<T>& items) {
        if (items.empty()) {
            throw std::invalid_argument("Vector is empty");
        }
        std::default_random_engine& engine = RandomEngineManager::get_instance().get_engine();
        std::uniform_int_distribution<size_t> dist(0, items.size() - 1);
        return items[dist(engine)];
    }

private:
    std::default_random_engine& engine = RandomEngineManager::get_instance().get_engine();
};

#endif // RANDOM_GENERATOR_HPP
