#include <iostream>

#include "picojson.h"

class Server
{
public:
    void run(picojson::object& configObject)
    {
        picojson::object& jObject = configObject;
        std::string s = jObject["type"].get<std::string>();
        if (s == "echo")
        {
            std::cout << "echo server" << std::endl;
            return;
        }
        std::cout << "check to type" << std::endl;
    }
};