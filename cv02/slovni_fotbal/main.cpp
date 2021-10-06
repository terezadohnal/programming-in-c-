//
//  main.cpp
//  slovni_fotbal
//
//  Created by Tereza Dohnalová on 29/09/2021.
//

#include <iostream>
#include "Game.hpp"

int main(int argc, const char * argv[]) {

    Game* game = new Game();
    game->start();
    
    return 0;
}
