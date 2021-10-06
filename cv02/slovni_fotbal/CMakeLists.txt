cmake_minimum_required(VERSION 3.17)
project(cv02)

set(CMAKE_CXX_STANDARD 14)

add_executable(cv02 main.cpp Game.cpp Game.hpp Dictionary.cpp Dictionary.hpp Channel.cpp Channel.hpp)