set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.1)
project(Digital_Design)

add_executable(dd logic_gates.hpp alu.hpp main.cpp)