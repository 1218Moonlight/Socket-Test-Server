cmake_minimum_required(VERSION 3.8)
project(Socket_Test_Server)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp config.h handler.h initlnclude.h)
add_executable(Socket_Test_Server ${SOURCE_FILES})