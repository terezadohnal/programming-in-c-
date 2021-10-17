//
// Created by Tereza  Dohnalova on 24/09/2021.
//

#ifndef CV1_HRA_MAZE_H
#define CV1_HRA_MAZE_H

#include "array"
#include "Tesla.h"
#include <vector>
#include "Position.h"

class Maze {
private:
    Tesla* tesla;
    std::vector<std::vector<char>> plan;

public:
    Maze();
    void print() const;
    bool checkDirection(int x, int y) const;
    bool checkSupercharger() const;
    void moveTesla(int x, int y);
    std::vector<std::vector<char>> loadMap(const std::string filename);
};

#endif //CV1_HRA_MAZE_H
