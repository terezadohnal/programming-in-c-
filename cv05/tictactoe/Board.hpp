//
//  Board.hpp
//  piskvorky
//
//  Created by Tereza Dohnalová on 20/10/2021.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include "Position.hpp"
#include <vector>
#include <iostream>

namespace TicTacToe {

template <class T> class Board{
private:
    std::vector<std::vector<T>> board;
    char m_defaultItem;
public:
    Board(unsigned int width, unsigned int height, T defaultItem);
    bool canBeInserted(TicTacToe::Position position);
    void insert(TicTacToe::Position position, T item);
    std::vector<std::vector<T>> getBoard();
    void print();
    void popRow();
    void popColumn();
    void appendRow(T defaultItem);
    void appendColumn(T defaultItem);

};

}

//template <class T> TicTacToe::Board<T>::Board(unsigned int width, unsigned int height, T defaultItem){
//    for (int i = 0; i < height; i++) {
//        for (int j = 0; j < width; j++) {
//            board.at(i).at(j) = defaultItem;
//        }
//    }
//}

template <class T>
TicTacToe::Board<T>::Board(unsigned int width, unsigned int height, T defaultItem){
    m_defaultItem = defaultItem;
    board = std::vector<std::vector<T>>(height, std::vector<T>(width,defaultItem));
}

template<class T>
bool TicTacToe::Board<T>::canBeInserted(TicTacToe::Position position){
    unsigned int height = board.size();
    unsigned int width = board.at(0).size();
    T currPos = board.at(position.row).at(position.column);

    return (position.row < width and position.column < height and currPos == m_defaultItem);
    //otazka: jestlize je position nastavena na unsigned int, tak teoreticky nemusime kontrolovat, zda je >= 0, je to tak?



//    return (
//            position.row >= 0
//            and position.row < board.size()
//            and position.column >= 0
//            and position.column < board.at(position.row).size()
//            and board.at(position.row).at(position.column) == m_defaultItem
//            );

};

template<class T>
void TicTacToe::Board<T>::insert(Position position, T item){
    board.at(position.row).at(position.column) = item;
}

template<class T>
std::vector<std::vector<T>> TicTacToe::Board<T>::getBoard() {
    return board;
}

template<class T> void TicTacToe::Board<T>::print(){
    for (auto i = board.begin(); i != board.end(); i++) {
        for (auto j = (*i).begin(); j != (*i).end(); j++) {
            std::cout << (*j);
        }
        std::cout << std::endl;
    }
}

template<class T> void TicTacToe::Board<T>::popRow(){
    board.pop_back();
};

template<class T> void TicTacToe::Board<T>::popColumn(){
    for (auto row: board) {
        row.pop_back();
    }
};

template<class T> void TicTacToe::Board<T>::appendRow(T defaultItem){
    unsigned int width = board.at(0).size();
    std::vector<T> row(width, defaultItem);
    board.push_back(row);
};

template<class T> void TicTacToe::Board<T>::appendColumn(T defaultItem){
    unsigned int height = board.size();
    for (int i = 0; i < height; i++) {
        board.at(i).push_back(defaultItem);
    }
};

#endif /* Board_hpp */
