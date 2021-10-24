cmake_minimum_required(VERSION 3.17)
project(CPP_cviceni05_piskvorky)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CPP_cviceni05_piskvorky
        GameEngine.cpp
        GameEngine.hpp
        main.cpp
        Position.hpp)
