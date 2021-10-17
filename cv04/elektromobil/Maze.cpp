//
// Created by Tereza  Dohnalova on 24/09/2021.
//

#include "Maze.h"
#include <iostream>
#include <fstream>

Maze::Maze() {
    tesla = new Tesla();
    plan = loadMap("map.txt");
}

std::vector<std::vector<char>> Maze::loadMap(const std::string filename){
    std::vector<std::vector<char>> plan(5);
    
    std::ifstream in(filename);
    std::string row;
    
    if (in.is_open()) {
        int j = 0;
        while (getline(in, row)) {
            plan.at(j).resize(5);
            for (int i = 0; i < row.length(); i++) {
                plan.at(j).at(i) = row.at(i);
            }
            j++;
        }
    } else {
        std::cerr << "I cant open the file" << std::endl;
    }
    
    return plan;
}


void Maze::print() const  {
    for (int y = 0; y < plan.size(); y++) {
        for (int x = 0; x < plan.at(y).size(); x++){
            if (tesla->getPosition().x == x and tesla->getPosition().y == y){
                std::cout << " T ";
            }else {
                std::cout << " "<< plan.at(y).at(x) << " ";
            }
        }
        std::cout << std::endl;
    }
}

bool Maze::checkDirection(int x, int y) const {
    int teslaX = tesla->getPosition().x;
    int teslaY = tesla->getPosition().y;

    if ((teslaX + x) > plan.size() - 1 or (teslaY + y) > plan.size() - 1 or (teslaX + x) < 0 or (teslaY + y) < 0){
        return false;
    }
    return true;
}

bool Maze::checkSupercharger() const{
    int teslaX = tesla->getPosition().x;
    int teslaY = tesla->getPosition().y;

    if (plan.at(teslaY).at(teslaX) == '+'){
        return true;
    }
    return false;
}


void Maze::moveTesla(int x, int y) {
    if (checkDirection(x, y)){
        tesla->setPosition(x, y);
        if (checkSupercharger()){
            tesla->setLevel(10);
        }
        tesla->printLevel();
    } else {
        std::cout << "Tesla cant go there, he's going out of the maze plan. Please go another direction." << std::endl;
    }
}


