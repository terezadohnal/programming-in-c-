//
// Created by Tereza  Dohnalova on 24/09/2021.
//

#include "Tesla.h"
#include <iostream>

//TODO: navysovat energii tesly

Tesla::Tesla() {
    position = Position{3, 3};
    setLevel(10);
}

Position Tesla::getPosition() {
    return position;
}

void Tesla::setPosition(int NewX, int NewY) {
    if (getLevel() > 0){
        position.x += NewX;
        position.y += NewY;
        decreaseLevel();
    } else {
        std::cerr << "The energy level is very low - tbh. ZERO" << std::endl;
        exit(0);
    }
}

void Tesla::setLevel(int energy){
    energyLevel = energy;
}

void Tesla::decreaseLevel() {
    energyLevel--;
}

int Tesla::getLevel(){
    return energyLevel;
}

void Tesla::printLevel(){
    std::cout << "Tesla's energy level is: " << getLevel() << std::endl;
}



