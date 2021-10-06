//
//  Game.hpp
//  slovni_fotbal
//
//  Created by Tereza Dohnalová on 29/09/2021.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include "Channel.hpp"
#include "Dictionary.hpp"

class Game {
private:
    Dictionary* dictionary;
    Channel* channel;
    bool isGameOver = false;
    
    void printIntro();
    void setIsGameOverToTrue();
    bool getIsGameOver();
public:
    Game();
    void start();
};

#endif /* Game_hpp */
