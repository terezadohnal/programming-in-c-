//
//  GameEngine.cpp
//  cpp_cviceni5_piskvorky
//
//  Created by David Prochazka on 10/23/12.
//  Copyright (c) 2012 David Prochazka. All rights reserved.
//

#include "GameEngine.hpp"

TicTacToe::GameEngine::GameEngine() {
    board = new TicTacToe::Board<char>(10, 10, '_');
}

void TicTacToe::GameEngine::start() {
    // TODO homework: enable game of more than 2 players
    std::string winningPlayer;

    while (winningPlayer.empty()) {
        Position aPosition = playOneTurn("Ivo");

        if (checkFiveInRow(aPosition)) {
            winningPlayer = "Ivo";
            board->print();
            break;
        }

        Position bPosition = playOneTurn("David");

        if (checkFiveInRow(bPosition)) {
            winningPlayer = "David";
            board->print();
            break;
        }
    }

    std::cout << "Player " << winningPlayer << " won.";
}

TicTacToe::Position TicTacToe::GameEngine::waitForInput(const std::string &player) const {
    Position position{};

    std::cout << "It's player " << player << "'s turn now:" << std::endl;

    do {
        std::cout << "Enter row: ";
        std::cin >> position.row;
        std::cout << "Enter column: ";
        std::cin >> position.column;
    } while (!board->canBeInserted(position));

    return position;
}

TicTacToe::Position TicTacToe::GameEngine::playOneTurn(const std::string &player) noexcept(false) {
    board->print();
    Position position = waitForInput(player);
    board->insert(position, player.at(0));
    return position;
}

TicTacToe::GameEngine::~GameEngine() {
    delete board;
}

bool TicTacToe::GameEngine::checkFiveInRow(const Position position) const {
    // TODO homework
    std::vector<std::vector<char>> thisBoard = board->getBoard();
    unsigned long width = thisBoard.at(0).size();
    bool isFive;
    int posCol = (int)position.column;

    int start = (posCol - 4 < 0) ? 0 : posCol - 4;

    for (int i = start; (i <= position.column) and (i <= width-4); i++) {
        isFive = true;
        for (int j = 0; j < 5; j++) {
            if (thisBoard.at(position.row).at(i+j) != thisBoard.at(position.row).at(position.column)){
                isFive = false;
                break;
            }
        }
        if (isFive) break;
    }
    return isFive;
}