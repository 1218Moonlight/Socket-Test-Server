#ifndef SOCKET_TEST_SERVER_SOCKET_H
#define SOCKET_TEST_SERVER_SOCKET_H

#include <winsock2.h>
#include <iostream>

class Socket {
private:
    u_short serverPort;
    SOCKET serverSock{}, clientSock{};
    WSADATA wsadata{};
    struct sockaddr_in serverInfo{}, clientInfo{};
    int clientSize{};
public:
    Socket(u_short serverPort);
    void run();
};

Socket::Socket(u_short serverPort) {
    this->serverPort = serverPort;
}

void Socket::run() {
    char message[] = "TEST";

    if (WSAStartup(MAKEWORD(2, 2), &this->wsadata) != 0 )
        std::cout << "Initialization failed." << std::endl;

    this->serverSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (this->serverSock == INVALID_SOCKET)
        std::cout << "Socket creation failed" << std::endl;

    memset(&this->serverInfo, 0, sizeof(this->serverInfo));

    this->serverInfo.sin_family = AF_INET;
    this->serverInfo.sin_port = htons(this->serverPort);
    this->serverInfo.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(this->serverSock, (SOCKADDR *) &this->serverInfo, sizeof(this->serverInfo)) == SOCKET_ERROR)
        std::cout << "Bind failed" << std::endl;

    if (listen(this->serverSock, 1) == SOCKET_ERROR)
        std::cout << "Queue Failed" << std::endl;

    this->clientSize = sizeof(this->clientInfo);

    std::cout << "Waiting for client access" << std::endl;

    this->clientSock = accept(this->serverSock, (SOCKADDR *) &this->clientInfo, &this->clientSize);

    if (this->clientSock == INVALID_SOCKET)
        std::cout << "Client socket connection failed" << std::endl;

    send(this->clientSock, message, sizeof(message), 0);

    closesocket(this->serverSock);
    closesocket(this->clientSock);

    WSACleanup();


}

#endif //SOCKET_TEST_SERVER_SOCKET_H
