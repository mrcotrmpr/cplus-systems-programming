#include "test_plugin.hpp"

std::string TestPlugin::name() const {
    return "TestPlugin";
}

std::string TestPlugin::description() const {
    return "A simple test plugin";
}

std::string TestPlugin::handle(const std::string& text) const
{
    return "Test";
}

IPlugin* create_instance() {
    return new TestPlugin;
}
