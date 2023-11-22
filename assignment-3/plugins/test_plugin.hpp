#ifndef TEST_PLUGIN_HPP
#define TEST_PLUGIN_HPP

#include "iplugin.hpp"

extern "C" {
	__declspec(dllexport) IPlugin* create_instance();
}

class TestPlugin : public IPlugin {
public:
	std::string name() const override;
	std::string description() const override;
	std::string handle(const std::string& text) const override;
};

#endif // TEST_PLUGIN_HPP;
