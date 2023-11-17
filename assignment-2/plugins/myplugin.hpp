#ifndef MYPLUGIN_HPP
#define MYPLUGIN_HPP

#include "iplugin.hpp"

extern "C" {
	__declspec(dllexport) IPlugin* create_instance();
}

class MyPlugin : public IPlugin {
public:
	std::string name() const override;
	std::string description() const override;
};

#endif // MYPLUGIN_HPP;
