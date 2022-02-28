cmake_minimum_required(VERSION 3.17)
project(assignment1)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment1 main.cpp)

configure_file(alice.txt alice.txt COPYONLY)

configure_file(test.txt test.txt COPYONLY)

