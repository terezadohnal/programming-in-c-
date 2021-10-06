//
//  Channel.cpp
//  slovni_fotbal
//
//  Created by Tereza Dohnalová on 29/09/2021.
//

#include "Channel.hpp"
#include <iostream>
#include <regex>

Channel::Channel(){}

void Channel::print(std::string text){
    std::cout << text << std::endl;
}

std::string Channel::waitForInput(){
    std::string input;
    std::cout << "Your word: " << std::endl;
    std::cin >> input;
    return input;
}

bool Channel::isInputWrong(std::string input){
    std::regex word("[[:alpha:]]+");
    if (regex_match(input,word)){
        return false;
    }
    print("Your input is not valid, please enter word.");
    return true;
}
