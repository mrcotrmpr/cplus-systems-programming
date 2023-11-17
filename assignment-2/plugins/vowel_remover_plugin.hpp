#ifndef VOWEL_REMOVER_PLUGIN_HPP
#define VOWEL_REMOVER_PLUGIN_HPP

#include "iplugin.hpp"

extern "C" {
	__declspec(dllexport) IPlugin* create_instance();
}

class VowelRemoverPlugin : public IPlugin {
public:
	std::string name() const override;
	std::string description() const override;
	std::string handle(const std::string& text) const override;
};

#endif // VOWEL_REMOVER_PLUGIN_HPP;
