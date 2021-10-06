//
//  Game.cpp
//  slovni_fotbal
//
//  Created by Tereza Dohnalová on 29/09/2021.
//

#include "Game.hpp"
#include <iostream>

Game::Game(){
    dictionary = new Dictionary();
    channel = new Channel();
}

void Game::printIntro(){
    std::cout << "Welcome, please enter first word: " << std::endl;
}

void Game::setIsGameOverToTrue() {
    isGameOver = true;
}

bool Game::getIsGameOver() {
    return isGameOver;
}

void Game::start() {
    std::string input, wordFound;
    printIntro();

    do {
    input = channel->waitForInput();
    } while (channel->isInputWrong(input));

    while (!getIsGameOver()){
        wordFound = dictionary->findWordWith(input.at(input.size()-1));
        if (wordFound == ""){
            channel->print("Word was not found. You won.");
            setIsGameOverToTrue();
        }else {
        channel->print("PC: " + wordFound);

        do {
            input = channel->waitForInput();
        } while (channel->isInputWrong(input));

        if (!dictionary->areWordsConnected(wordFound, input)){
            channel->print("Your word starts with wrong letter. System won.");
            setIsGameOverToTrue();
        }
        }
    }
}

