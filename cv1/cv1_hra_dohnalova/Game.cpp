//
// Created by Tereza  Dohnalova on 24/09/2021.
//

#include "Game.h"
#include <iostream>

Game::Game() {
    maze = new Maze();
    status = true;
}

void Game::printIntroduction() const {
    std::cout << "Welcome to the game." << std::endl;
}

void Game::printOptions() const {
    std::cout << "Enter W to go up" << std::endl;
    std::cout << "Enter A to go left" << std::endl;
    std::cout << "Enter S to go down" << std::endl;
    std::cout << "Enter D to go right" << std::endl;
    std::cout << "Enter Q to quit the game" << std::endl;
}

void Game::setStatus(bool newStatus) {
    status = newStatus;
}

bool Game::getStatus() {
    return status;
}

char Game::waitForInput() const {
    char input;
    std::cin >> input;
    return input;
}

void Game::start() {
    printIntroduction();
    while (getStatus()){
        maze->print();
        printOptions();
        char input = waitForInput();
        processInput(input);
    }
}

void Game::processInput(char input) {
    if (input == 'W' or input == 'A' or input == 'S' or input == 'D' or input == 'Q'){
        if (input == 'W'){
            maze->moveWorm(0, -1);
        } else if (input == 'A'){
            maze->moveWorm(-1, 0);
        }else if (input == 'S'){
            maze->moveWorm(0, 1);
        }else if (input == 'D'){
            maze->moveWorm(1, 0);
        } else {
            setStatus(false);
            std::cout << "GAME OVER" << std::endl;
        }
    } else {
        std::cout << "You've entered wrong input, try again" << std::endl;
    }
}

