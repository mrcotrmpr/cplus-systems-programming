#ifndef IPLUGIN_HPP
#define IPLUGIN_HPP

#include <string>

class IPlugin {
public:
	virtual ~IPlugin() = default;
	virtual std::string name() const = 0;
	virtual std::string description() const = 0;
};

#endif // IPLUGIN_HPP
