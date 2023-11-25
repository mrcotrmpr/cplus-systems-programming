#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <string>

const std::string FILE_ONE = "shared_file_1.txt";
const std::string FILE_TWO = "shared_file_2.txt";
std::mutex fileMutex;

void write(std::string file_name) {
    std::lock_guard <std::mutex> lock(fileMutex);

    std::ofstream file(file_name, std::ios::app);
    file << "This is a line written by thread: " << std::this_thread::get_id() << std::endl;
    file.close();
}

void read(std::string file_name) {
    std::lock_guard <std::mutex> lock(fileMutex);

    std::ifstream file(file_name);
    std::string content;
    while (std::getline(file, content)) {
        std::cout << "Thread: " << std::this_thread::get_id() << " - Reading: " << content << std::endl;
    }
    std::cout << '\n';
    file.close();
}

void clear() {
    for (const std::string& fileName : { FILE_ONE, FILE_TWO }) {
        std::ofstream file(fileName, std::ofstream::trunc);
        file.close();
    }
}

void file_operations() {
    write(FILE_ONE);
    write(FILE_TWO);
    read(FILE_ONE);
    read(FILE_TWO);
}

int main() {
    std::thread threads[2];

    for (int i = 0; i < 2; ++i) {
        threads[i] = std::thread(file_operations);
    }

    for (int i = 0; i < 2; ++i) {
        threads[i].join();
    }

    clear();

    return 0;
}
