//
//  Loader.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include "Loader.hpp"


std::vector<Conversation> Loader::getConversations(const std::string filename) const
{
    std::vector<Conversation> conversations;

    // TODO
    //načítání ze souboru, použití fstreamu
    
    std::ifstream in(filename); //input file stream, posíláme do něj název souboru
    std::string row; // do tohoto budu načítat řádek
    
    if (in.is_open()) { //důležitá kontrola
        while (getline(in, row)) {
            //std::cout << row << std::endl; // otestování, ještě neřešíme rozdělování řádku
            Conversation conversation = splitLine(row);
            conversations.push_back(conversation);
        }
    }else {
        std::cerr << "File does not exist or is not available." << std::endl;
    }
    
    return conversations;
}

Conversation Loader::splitLine(const std::string line) const {
    // TODO
    size_t position = line.find(" ");
    std::string keyword = line.substr(0, position);
    std::string answer = line.substr(position + 1, line.length()-1); //length nečísluje od 0
    
    std::regex regex(".*" + keyword + ".*"); // tohle musíme poslat do conversation, protože je tam uložen dat. typ regex
    
    //.* - matchujeme uplně cokoliv
    
    return {regex, answer}; // samo to vytvoří instanci conversations a pošle tam tyto udaje
}
