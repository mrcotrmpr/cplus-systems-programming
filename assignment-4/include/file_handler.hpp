#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <iostream>
#include <fstream>
#include <mutex>
#include <string>

class FileHandler {
private:
    std::string file_name;
    std::mutex file_mutex;

public:
    FileHandler(const std::string& filename);

    void write(const std::string& content);
    void read();
    std::lock_guard<std::mutex> lock();
    void clear();
};

#endif // FILE_HANDLER_HPP
