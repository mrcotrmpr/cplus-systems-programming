#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include "string"

#include "lib/include/split_join.hpp"
#include "lib/include/random_generator.hpp"

int main() {
    std::ifstream file("data/Alice_in_Wonderland.txt");
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(file, line)) {
        lines.push_back(line);
    }

    lines = rg::choose_random_items(lines, 10);

    std::regex pat{R"([^[:alpha:]]+)"};
    std::map<std::string, int> wordCounts{};

    for (const auto& line : lines)
    {
        for (const auto& word : sp::split(line, pat))
        {
            if (wordCounts.find(word) == wordCounts.end()) {
                wordCounts[word] = 1;
            }
            else {
                wordCounts[word]++;
            }
        }
    }

    for (const auto& pair : wordCounts) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
