#ifndef SPLIT_JOIN_HPP
#define SPLIT_JOIN_HPP

#include <string>
#include <vector>
#include <regex>

namespace sp {
    std::vector<std::string> split(const std::string& str, const std::string& sep);
    std::vector<std::string> split(const std::string& str, const std::regex& sep);
    std::string join(const std::vector<std::string>& components, const std::string& join);
}

#endif // SPLIT_JOIN_HPP
