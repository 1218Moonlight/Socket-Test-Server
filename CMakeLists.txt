cmake_minimum_required(VERSION 3.8)
project(Socket_Test_Server)

set(CMAKE_CXX_STANDARD 17)

link_libraries(ws2_32 wsock32)

set(SOURCE_FILES main.cpp config.h handler.h socket.h)
add_executable(Socket_Test_Server ${SOURCE_FILES})