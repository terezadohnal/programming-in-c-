cmake_minimum_required(VERSION 3.17)
project(cv1_hra)

set(CMAKE_CXX_STANDARD 14)

add_executable(cv1_hra main.cpp Game.cpp Game.h Maze.cpp Maze.h Worm.cpp Worm.h Position.cpp Position.h)