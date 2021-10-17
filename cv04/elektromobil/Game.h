//
// Created by Tereza  Dohnalova on 24/09/2021.
//

#ifndef CV1_HRA_GAME_H
#define CV1_HRA_GAME_H

#include "Maze.h"

 class Game {
 private:
    Maze* maze;
    bool status;
    void printIntroduction() const;
    void printOptions() const;
    char waitForInput() const;
    void processInput(char input);
    void setStatus(bool newStatus);
    bool getStatus();
 public:
    Game();
    void start();
};

#endif //CV1_HRA_GAME_H
