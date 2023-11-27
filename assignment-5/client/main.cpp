#include <iostream>
#include <string>
#include <cstring>
#include "networking.hpp"
#include "throw.hpp"

std::string read_line(int sock) {
    std::string result;
    char c{};
    int n{ 0 };
    while ((n = recv(sock, &c, 1, 0)) > 0 && c != '\n') {
        throw_if_min1(n);
        result += c;
    }
    return result;
}

int main() {
    try {
        // create stream socket
        int server{ 0 };
        throw_if_min1(server = socket(AF_INET, SOCK_STREAM, 0));

        // fill in address struct with server address
        struct sockaddr_in sa;
        std::memset(&sa, 0, sizeof(struct sockaddr_in));
        sa.sin_family = AF_INET;
        sa.sin_port = htons(4242);
        throw_if_min1(inet_pton(AF_INET, "127.0.0.1", &sa.sin_addr.s_addr));

        // connect to server
        throw_if_min1(connect(server,
            reinterpret_cast<struct sockaddr*>(&sa),
            sizeof(sa)));

        // read the message from the server
        std::string resp = read_line(server);
        std::cout << "client: received from server: " << resp << std::endl;

        // cleanup
        throw_if_min1(closesocket(server));

    }
    catch (const std::exception& ex) {
        std::cerr << "client: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
