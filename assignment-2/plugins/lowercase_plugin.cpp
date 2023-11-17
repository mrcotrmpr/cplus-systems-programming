#include "lowercase_plugin.hpp"

std::string LowercasePlugin::name() const {
    return "LowercasePlugin";
}

std::string LowercasePlugin::description() const {
    return "Transform text to lower case.";
}

std::string LowercasePlugin::handle(const std::string& text) const
{
    std::string result = text;
    for (char& c : result) {
        c = std::tolower(c);
    }
    return result;
}

IPlugin* create_instance() {
    return new LowercasePlugin;
}
