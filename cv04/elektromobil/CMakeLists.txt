cmake_minimum_required(VERSION 3.17)
project(cv04 )

set(CMAKE_CXX_STANDARD 14)

add_executable(cv04 main.cpp Maze.h Maze.cpp Position.h Position.cpp Game.h Game.cpp Tesla.h Tesla.cpp)