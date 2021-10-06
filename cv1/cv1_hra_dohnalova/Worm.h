//
// Created by Tereza  Dohnalova on 24/09/2021.
//

#ifndef CV1_HRA_WORM_H
#define CV1_HRA_WORM_H

#include "Position.h"

class Worm {
private:
    Position position{};

public:
    Worm();
    Position getPosition();
    void setPosition(int NewX, int NewY);
};

#endif //CV1_HRA_WORM_H
