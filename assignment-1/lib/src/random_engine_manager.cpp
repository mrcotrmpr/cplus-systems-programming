#include "include/random_engine_manager.hpp"

RandomEngineManager::RandomEngineManager() : engine(device()) {}

RandomEngineManager& RandomEngineManager::get_instance() {
    static RandomEngineManager instance;
    return instance;
}

std::default_random_engine& RandomEngineManager::get_engine() {
    return engine;
}
