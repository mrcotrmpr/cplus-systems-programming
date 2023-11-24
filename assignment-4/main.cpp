#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <string>

const std::string FILE_ONE = "shared_file-1.txt";
const std::string FILE_TWO = "shared_file-2.txt";
std::mutex fileMutex;

void write(std::string file_name) {
    std::unique_lock<std::mutex> lock(fileMutex);

    std::ofstream file(file_name, std::ios::app);
    file << "This is a line written by thread: " << std::this_thread::get_id() << std::endl;
    file.close();
}

void read(std::string file_name) {
    std::unique_lock<std::mutex> lock(fileMutex);

    std::ifstream file(file_name);
    std::string content;
    while (std::getline(file, content)) {
        std::cout << "Thread: " << std::this_thread::get_id() << " - Reading: " << content << std::endl;
    }
    std::cout << '\n';
    file.close();
}

void clear() {
    std::ofstream file1(FILE_ONE, std::ofstream::trunc);
    file1.close();

    std::ofstream file2(FILE_TWO, std::ofstream::trunc);
    file2.close();
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
