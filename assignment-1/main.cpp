#include <iostream>
#include "lib/include/split_join.hpp"
#include "lib/include/random_generator.hpp"

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

    std::shared_ptr<RandomGenerator> randomGenerator = std::make_shared<RandomGenerator>();

    int testInt = randomGenerator->generate_random_int(1, 10);
    std::cout << "Random integer: " << testInt << std::endl;

    double testDouble = randomGenerator->generate_random_double(1.0, 10.0);
    std::cout << "Random double: " << testDouble << std::endl;

    double testDoubleZeroToOne = randomGenerator->generate_double_zero_to_one();
    std::cout << "Random double between 0 and 1: " << testDoubleZeroToOne << std::endl;

    bool testBool = randomGenerator->generate_random_bool();
    std::cout << "Random bool: " << (testBool ? "true" : "false") << std::endl;

    std::vector<char> stringVector = { 'A', 'B', 'C', 'D', 'E' };
    char randomChar = randomGenerator->choose_random_item(stringVector);
    std::cout << "Random item from string vector: " << randomChar << std::endl;

    std::vector<int> intVector = { 1, 2, 3, 4, 5, 6 };
    int randomInt = randomGenerator->choose_random_item(intVector);
    std::cout << "Random item from int vector: " << randomInt << std::endl;

	return 0;
}
