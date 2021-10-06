//
//  Channel.hpp
//  slovni_fotbal
//
//  Created by Tereza Dohnalová on 29/09/2021.
//

#ifndef Channel_hpp
#define Channel_hpp

#include <stdio.h>
#include <string>

// komunikační kanál

class Channel {
public:
    Channel();
    void print(std::string text);
    std::string waitForInput();
    bool isInputWrong(std::string input);
};

#endif /* Channel_hpp */
