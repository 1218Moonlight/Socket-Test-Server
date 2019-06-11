#include <iostream>

#include "./config/main.cpp"

int main() {
    Config config("config.json");
    config.read();
    return 0;
}