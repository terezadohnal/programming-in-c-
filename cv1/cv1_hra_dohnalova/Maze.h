//
// Created by Tereza  Dohnalova on 24/09/2021.
//

#ifndef CV1_HRA_MAZE_H
#define CV1_HRA_MAZE_H

#include "array"
#include "Worm.h"

class Maze {
private:
    Worm* worm;
    std::array<std::array<char,5>,5> plan;

public:
    Maze();
    void print() const;
    bool checkDirection(int x, int y) const;
    void moveWorm(int x, int y);
};

#endif //CV1_HRA_MAZE_H
