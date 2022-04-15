cmake_minimum_required(VERSION 3.21)
project(assignment5)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment5 main.cpp Tracker.cpp DynamicArray.cpp FileWriter.cpp Logger.cpp)

target_compile_options(assignment5 PRIVATE -Og -Wall -Wextra -Werror -pedantic)