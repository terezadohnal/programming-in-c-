//
//  Chatbot.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include "Chatbot.hpp"
#include <iostream>
#include <regex>

Chatbot::Chatbot(const std::string filename) {
    // TODO

    Loader loader;
    m_conversations = loader.getConversations(filename);
    
}

void Chatbot::chat() const {
    // TODO
    while(true){
        std::string input = getUserSentence();
        std::string answer = findAnswer(input);
        printAnswer(answer);
    }
}

std::string Chatbot::getUserSentence() const {
    // TODO
    // načítání celého řádku
    
    std::string input;
    std::cout << "Enter your input: " << std::endl;
    getline(std::cin, input);
    return input;
}

std::string Chatbot::findAnswer(const std::string userSentence) const {
    // TODO
    // regex
        
    for (auto conv: m_conversations) {
        if(std::regex_match(userSentence, conv.keyword)) {
            return conv.response;
        } else {
            return "";
        }
    }
 
    return "";
}

void Chatbot::printAnswer(const std::string computerAnswer) const{
    std::cout << "Computers answer is: " << computerAnswer << std::endl;
}
