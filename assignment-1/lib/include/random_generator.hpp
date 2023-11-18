#ifndef RANDOM_GENERATOR_HPP
#define RANDOM_GENERATOR_HPP

#include "include/random_engine_manager.hpp"

namespace rg {
    int generate_random_int(int lower, int upper);
    double generate_random_double(double lower, double upper);
    double generate_double_zero_to_one();
    bool generate_random_bool();
    std::default_random_engine& engine = RandomEngineManager::get_instance().get_engine();

    template <typename T>
    std::vector<T> choose_random_items(const std::vector<T>& items, int amount) {
        if (items.empty()) {
            throw std::invalid_argument("Vector is empty");
        }

        std::default_random_engine& engine = RandomEngineManager::get_instance().get_engine();
        std::uniform_int_distribution<size_t> dist(0, items.size() - 1);

        std::vector<T> randomItems;
        randomItems.reserve(amount); // Reserve space for 'amount' items

        for (int i = 0; i < amount; ++i) {
            randomItems.push_back(items[dist(engine)]);
        }

        return randomItems;
    }
};

#endif // RANDOM_GENERATOR_HPP
