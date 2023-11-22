#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <memory>
#include <fstream>

#include "plugin_wrapper.hpp"
#include "iplugin.hpp"

int main(int argc, char* argv[]) {
	try {
		using factory = IPlugin* (*)();
		PluginWrapper wrapper{"plugins/" + std::string(argv[1])};
		factory func = reinterpret_cast<factory>(wrapper.lookup("create_instance"));
		std::unique_ptr<IPlugin> plugin{func()};

		std::cout << "Plugin: " << plugin->name() << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
}
