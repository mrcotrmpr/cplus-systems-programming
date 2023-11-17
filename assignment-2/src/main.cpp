#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <memory>
#include <fstream>

#include "plugin_wrapper.hpp"
#include "iplugin.hpp"

std::vector<std::string> scan_dir(const std::string& path, const std::string& ext) {
    std::vector<std::string> plugins;
    for (const auto& entry : std::filesystem::directory_iterator{ path }) {
        std::string filename {entry.path().string()};
        if (filename.substr(filename.size() - ext.size(), ext.size()) == ext) {
            plugins.push_back(filename);
        }
    }
    return plugins;
}

void display_plugins(const std::vector<std::unique_ptr<IPlugin>>& plugins, const std::vector<bool>& pluginStatus) {
    system("cls");
    std::cout << "Available Plugins:\n";
    for (size_t i = 0; i < plugins.size(); ++i) {
        std::cout << i << ": " << plugins[i]->name() << " - " << (pluginStatus[i] ? "enabled" : "disabled") << '\n';
    }
}

std::string process_text(const std::vector<std::unique_ptr<IPlugin>>& plugins, const std::vector<bool>& pluginStatus) {
    std::ifstream inputFile("data/input.txt");
    std::string inputText, line;
    while (std::getline(inputFile, line)) {
        inputText += line + '\n';
    }
    inputFile.close();

    for (size_t i = 0; i < plugins.size(); ++i) {
        if (pluginStatus[i]) {
            inputText = plugins[i]->handle(inputText);
        }
    }
    return inputText;
}

int main() {
    try {
        std::vector<std::string> files = scan_dir("plugins", "plug");
        std::vector<PluginWrapper> pluginWrappers;
        for (const std::string& file : files) {
            pluginWrappers.emplace_back(file);
        }

        using factory = IPlugin * (*)();
        std::vector<std::unique_ptr<IPlugin>> plugins;
        for (const PluginWrapper& wrapper : pluginWrappers) {
            factory func = reinterpret_cast<factory>(wrapper.lookup("create_instance"));
            plugins.emplace_back(func());
        }

        std::vector<bool> pluginStatus(plugins.size(), true);
        bool text_processed = false;

        char choice;
        do {
            display_plugins(plugins, pluginStatus);
            std::cout << "Enter the index of the plugin to toggle enable/disable, or 'e' to process input: ";
            std::cin >> choice;

            if (isdigit(choice)) {
                size_t index = static_cast<size_t>(choice - '0');
                if (index < plugins.size()) {
                    pluginStatus[index] = !pluginStatus[index];
                }
            }
            else if (choice == 'e') {
                std::cout << process_text(plugins, pluginStatus) << std::endl;
                text_processed = true;
            }
        } while (!text_processed);

    }
    catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
