#include "include/split_join.hpp"

std::vector<std::string> sp::split(const std::string& str, const std::string& sep)
{
    std::vector<std::string> words;
    std::size_t start = 0, end = 0;

    while ((end = str.find(sep, start)) != std::string::npos) {
        words.push_back(str.substr(start, end - start));
        start = end + sep.length();
    }

    words.push_back(str.substr(start));
    return words;
}

std::vector<std::string> sp::split(const std::string& str, const std::regex& sep)
{
    std::vector<std::string> words;

    std::sregex_token_iterator it(str.begin(), str.end(), sep, -1);
    std::sregex_token_iterator end;

    while (it != end) {
        words.push_back(*it);
        ++it;
    }

    return words;
}

std::string sp::join(const std::vector<std::string>& components, const std::string& join) {
    if (components.empty()) {
        return "";
    }

    std::string joinedString = components[0];

    for (size_t i = 1; i < components.size(); ++i) {
        joinedString += join + components[i];
    }

    return joinedString;
}
