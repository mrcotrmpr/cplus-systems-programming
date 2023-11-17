#include "myplugin.hpp"

std::string MyPlugin::name() const {
    return "myplugin";
}

std::string MyPlugin::description() const {
    return "works";
}

IPlugin* create_instance() {
    return new MyPlugin;
}
