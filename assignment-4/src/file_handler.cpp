#include "file_handler.hpp"

FileHandler::FileHandler(const std::string& filename) : file_name(filename) {}

void FileHandler::write(const std::string& content) {
    std::ofstream file(file_name, std::ios::app);
    file << content << std::endl;
}

void FileHandler::read() {
    std::ifstream file(file_name);
    std::string content;
    while (std::getline(file, content)) {
        std::cout << "Thread: " << std::this_thread::get_id() << " - Reading: " << content << std::endl;
    }
    std::cout << '\n';
}

std::lock_guard<std::mutex> FileHandler::lock() {
    return std::lock_guard<std::mutex>{file_mutex};
}

void FileHandler::clear() {
    std::ofstream file(file_name, std::ofstream::trunc);
}
