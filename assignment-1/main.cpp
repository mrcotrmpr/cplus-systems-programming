#include <iostream>
#include "lib/include/split_join.hpp"

int main() {
    // Split based on space
    std::string sentence {"In this sentence there are seven words."};
    std::vector<std::string> words {sp::split(sentence, " ")};
    for (const auto& word : words) {
        std::cout << word << '\n';
    }

    // Join with hyphen
    std::cout << sp::join(words, "-") << '\n';

    // Split based on regular expression
    std::string text {"123.456,789#012"};
    std::regex pattern {R"([.,#])"}; // R"()" is a raw string
    for (const auto& part : sp::split(text, pattern)) {
        std::cout << part << ' ';
    }
    std::cout << '\n';


	return 0;
}
