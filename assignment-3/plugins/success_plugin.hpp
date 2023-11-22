#ifndef SUCCESS_PLUGIN_HPP
#define SUCCESS_PLUGIN_HPP

#include "iplugin.hpp"

extern "C" {
	__declspec(dllexport) IPlugin* create_instance();
}

class SuccessPlugin : public IPlugin {
public:
	std::string name() const override;
	std::string description() const override;
	std::string handle(const std::string& text) const override;
};

#endif // SUCCESS_PLUGIN_HPP;
