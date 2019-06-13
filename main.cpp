#include "initInclude.h"
#include "config.h"
#include "server.h"

Server server;

int main()
{
    Config config("config.json");

    picojson::object& configObj = config.read();

    
    server.run(configObj);

    return 0;
}