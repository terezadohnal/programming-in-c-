cmake_minimum_required(VERSION 3.17)
project(cv03)

set(CMAKE_CXX_STANDARD 14)

add_executable(cv03 chatbot/main.cpp chatbot/Chatbot.hpp chatbot/Chatbot.cpp chatbot/Loader.hpp chatbot/Loader.cpp chatbot/Conversation.hpp)