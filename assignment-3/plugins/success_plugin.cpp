#include "success_plugin.hpp"

std::string SuccessPlugin::name() const {
    return "SuccessPlugin";
}

std::string SuccessPlugin::description() const {
    return "A plugin which doesn't crash";
}

std::string SuccessPlugin::handle(const std::string& text) const
{
    return "Success";
}

IPlugin* create_instance() {
    return new SuccessPlugin;
}
