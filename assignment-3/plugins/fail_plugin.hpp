#ifndef FAIL_PLUGIN_HPP
#define FAIL_PLUGIN_HPP

#include "iplugin.hpp"

extern "C" {
	__declspec(dllexport) IPlugin* create_instance();
}

class FailPlugin : public IPlugin {
public:
	std::string name() const override;
	std::string description() const override;
	std::string handle(const std::string& text) const override;
};

#endif // FAIL_PLUGIN_HPP;
