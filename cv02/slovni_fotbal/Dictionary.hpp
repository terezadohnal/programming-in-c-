//
//  Dictionary.hpp
//  slovni_fotbal
//
//  Created by Tereza Dohnalová on 29/09/2021.
//

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include <stdio.h>
#include <string>
#include <vector>

class Dictionary{
private:
    std::vector<std::string> words;
public:
    Dictionary();
    bool areWordsConnected(std::string word1, std::string word2);
    std::string findWordWith(char character);

};

#endif /* Dictionary_hpp */
