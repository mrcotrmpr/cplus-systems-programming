#ifndef RANDOM_ENGINE_MANAGER_HPP
#define RANDOM_ENGINE_MANAGER_HPP

#include <random>

class RandomEngineManager {
public:
    static RandomEngineManager& get_instance();

    std::default_random_engine& get_engine();

private:
    RandomEngineManager();

    std::random_device device;
    std::default_random_engine engine;
};

#endif // RANDOM_ENGINE_MANAGER_HPP
