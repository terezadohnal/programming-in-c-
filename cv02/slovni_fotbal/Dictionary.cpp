//
//  Dictionary.cpp
//  slovni_fotbal
//
//  Created by Tereza Dohnalová on 29/09/2021.
//

#include "Dictionary.hpp"

Dictionary::Dictionary(){
    words = {"alfa","bravo", "delta", "echo", "golf", "hotel", "juliet", "kilo", "lima", "mike", "oscar", "quebec", "romeo", "sierra", "tango", "uniform", "victor", "whiskey", "yankee", "zulu"};
}

bool Dictionary::areWordsConnected(std::string word1, std::string word2){
    if (word1.at(word1.size()-1) == word2.at(0)) {
        return true;
    }
    return false;
}

std::string Dictionary::findWordWith(char character){
    std::string result = "";
    
    for (auto word: words) {
        if (word.at(0) == character) {
            result = word;
            return result;
        }
    }
    return result;
}

