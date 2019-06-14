#ifndef SOCKET_TEST_SERVER_HANDLER_H
#define SOCKET_TEST_SERVER_HANDLER_H

class Handler {
private:
    std::string sType;
public:
    void routing(picojson::object& configObject);
};

void Handler::routing(picojson::object& configObject) {
    picojson::object& jObject = configObject;
    this->sType = jObject["type"].get<std::string>();
    if (this->sType == "echo") {
        std::cout << "echo server" << std::endl;
        return;
    }
    std::cout << "check to type" << std::endl;
}

#endif //SOCKET_TEST_SERVER_HANDLER_H
