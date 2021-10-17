//
//  main.cpp
//  elektromobil
//
//  Created by Tereza Dohnalová on 13/10/2021.
//

#include <iostream>
#include "Game.h"

int main(int argc, const char * argv[]) {
    
    Game *game = new Game();
    game->start();

    return 0;
}
