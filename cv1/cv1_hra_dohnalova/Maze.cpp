//
// Created by Tereza  Dohnalova on 24/09/2021.
//

#include "Maze.h"
#include <iostream>

Maze::Maze() {
    worm = new Worm();
}

void Maze::print() const  {
    for (int y = 0; y < plan.size(); y++) {
        for (int x = 0; x < plan.at(y).size(); x++){
            if (worm->getPosition().x == x and worm->getPosition().y == y){
                std::cout << " @ ";
            } else {
                std::cout << " x ";
            }
        }
        std::cout << std::endl;
    }
}

bool Maze::checkDirection(int x, int y) const {
    int wormX = worm->getPosition().x;
    int wormY = worm->getPosition().y;

    if ((wormX + x) > plan.size() - 1 or (wormY + y) > plan.size() - 1 or (wormX + x) < 0 or (wormY + y) < 0){
        return false;
    }
    return true;
}

void Maze::moveWorm(int x, int y) {
    if (checkDirection(x, y)){
        worm->setPosition(x, y);
    } else {
        std::cout << "Worm cant go there, he's going out of the maze plan. Please go another direction." << std::endl;
    }
}


