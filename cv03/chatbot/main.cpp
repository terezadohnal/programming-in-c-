//
//  main.cpp
//  Chatbot
//
//  Created by David Procházka on 11/10/2018.
//  Copyright © 2018 MENDELU. All rights reserved.
//

#include <iostream>
#include "Loader.hpp"
#include "Chatbot.hpp"

// pOkud nefunguje načítání ze souboru je potřeba upravit cestu k souboru: Product -> Scheme -> edit scheme -> najít cestu ke zdrojákum

int main(int argc, const char * argv[]) {

//    Loader pokus;
//    std::vector<Conversation> conversations = pokus.getConversations("chat.txt");
//
//    for(auto conv : conversations){
//        std::cout << "R: " << conv.response << std::endl;
//    }
    
    //Chatbot chatbot("chat.txt");
    //chatbot.chat();
    
//    Loader pokus;
//    std::vector<Conversation> conversation = pokus.getConversations("chat.txt");
    
//    for (auto conv: conversation) {
//        std::cout << conv.response << std::endl;
//    }

    Chatbot *chatbot = new Chatbot("chat.txt");
    chatbot->chat();
    
    return 0;
}
