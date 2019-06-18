#ifndef SOCKET_TEST_SERVER_HANDLER_H
#define SOCKET_TEST_SERVER_HANDLER_H

#include "picojson.h"
#include "socket.h"

class Handler {
private:
    std::string sType;
    Socket socket;
public:
    void routing(picojson::object& configObject);
};

void Handler::routing(picojson::object& configObject) {
    picojson::object& jObject = configObject;
    this->sType = jObject["type"].get<std::string>();
    if (this->sType == "echo") {
        std::cout << "echo server" << std::endl;
        socket.run();
        return;
    }
    std::cout << "check to type" << std::endl;
}

#endif //SOCKET_TEST_SERVER_HANDLER_H
