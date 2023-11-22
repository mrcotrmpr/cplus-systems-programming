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
        std::string pluginsDirectory = "plugins/";
        for (int i = 1; i < argc; ++i) {
            std::string pluginPath = pluginsDirectory + std::string(argv[i]);

            PluginWrapper wrapper{ pluginPath };
            using factory = IPlugin * (*)();
            factory func = reinterpret_cast<factory>(wrapper.lookup("create_instance"));

            std::unique_ptr<IPlugin> plugin{func()};

            std::cout << "Name: " << plugin->name() << std::endl;
            std::cout << "Description: " << plugin->description() << std::endl;
            std::string test = plugin->handle("This is a test");
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
