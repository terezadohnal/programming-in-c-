//
// Created by Tereza  Dohnalova on 24/09/2021.
//

#ifndef CV1_HRA_WORM_H
#define CV1_HRA_WORM_H

#include "Position.h"

class Tesla {
private:
    Position position{};
    int energyLevel;
    int getLevel();
public:
    Tesla();
    Position getPosition();
    void setPosition(int NewX, int NewY);
    void setLevel(int energy);
    void decreaseLevel();
    void printLevel();
};

#endif //CV1_HRA_WORM_H
