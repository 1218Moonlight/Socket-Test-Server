#include "initlnclude.h"
#include "config.h"
#include "handler.h"

int main() {
    Config config("./../config.json");

    Handler handler;

    handler.routing(config.picojsonObject());

    return 0;
}