cmake_minimum_required(VERSION 3.17)
project(assignment3)

set(CMAKE_CXX_STANDARD 20)

add_executable(assignment3 main.cpp Rational.cpp Rational_Calc.cpp Rational_processor.cpp)

configure_file(test.in test.in COPYONLY)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -pedantic")