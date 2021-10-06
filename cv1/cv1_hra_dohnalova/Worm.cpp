//
// Created by Tereza  Dohnalova on 24/09/2021.
//

#include "Worm.h"

Worm::Worm() {
    position = Position{3, 3};
}

Position Worm::getPosition() {
    return position;
}

void Worm::setPosition(int NewX, int NewY) {
position.x += NewX;
position.y += NewY;
}
