#include "fail_plugin.hpp"

std::string FailPlugin::name() const {
    return "FailPlugin";
}

std::string FailPlugin::description() const {
    return "A plugin which does crash";
}

std::string FailPlugin::handle(const std::string& text) const
{
    return "Fail";
}

IPlugin* create_instance() {
    return nullptr;
}
