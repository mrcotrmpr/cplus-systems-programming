#include "vowel_remover_plugin.hpp"

std::string VowelRemoverPlugin::name() const {
    return "VowelRemoverPlugin";
}

std::string VowelRemoverPlugin::description() const {
    return "Remove vowels from text.";
}

std::string VowelRemoverPlugin::handle(const std::string& text) const
{
    std::string result;
    for (char c : text) {
        char lowercase = std::tolower(c);
        if (!(lowercase == 'a' || lowercase == 'e' || lowercase == 'i' || lowercase == 'o' || lowercase == 'u')) {
            result += c;
        }
    }
    return result;
}

IPlugin* create_instance() {
    return new VowelRemoverPlugin;
}
