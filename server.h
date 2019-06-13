#ifndef server_h
#define server_h

class Server
{
private:
    std::string sType;

public:
    void run(picojson::object& configObject);
};

void Server::run(picojson::object& configObject)
{
    picojson::object& jObject = configObject;
    this->sType = jObject["type"].get<std::string>();
    if (this->sType == "echo")
    {
        std::cout << "echo server" << std::endl;
        return;
    }
    std::cout << "check to type" << std::endl;
}

#endif