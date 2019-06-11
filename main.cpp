#include <iostream>

#include "config.cpp"
#include "picojson.h"
#include "server.cpp"

Server server;

int main()
{
    Config config("config.json");

    picojson::object& configObj = config.read();

    server.run(configObj);

    return 0;
}