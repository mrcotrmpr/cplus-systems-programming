#include <thread>
#include <sstream>

#include "file_handler.hpp"

FileHandler file1("shared_file_1.txt");
FileHandler file2("shared_file_2.txt");

void file_operations() {
    auto lock1 = file1.lock();
    auto lock2 = file2.lock();

    std::stringstream ss;
    ss << "This is a line written by thread: " << std::this_thread::get_id();
    file1.write(ss.str());
    file2.write(ss.str());

    file1.read();
    file2.read();
}

int main() {
    std::thread threads[2];
    for (int i = 0; i < 2; ++i) {
        threads[i] = std::thread(file_operations);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    file1.clear();
    file2.clear();

    return 0;
}
