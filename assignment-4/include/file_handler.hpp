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

    std::mutex& get_mutex() { return file_mutex; }

    void write(const std::string& content);
    void read();
    void clear();
};

#endif // FILE_HANDLER_HPP
