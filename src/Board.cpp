#include "../include/Board.h"
#include <iostream>


void BOARD::init() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = DIGITS[i * BOARD_SIZE + j];
        }
    }
    mark = 'X';
}

void BOARD::draw() {
    std::cout<<"-  -  -  -  -\n";
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout<< "| " << std::endl;
        std::cout<<"-  -  -  -  -\n";
    }
}

bool BOARD::checkWin(){
    // check lines
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] == board[i][2]) {
            return true;
        }
    }
    // check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] == board[2][i]) {
            return true;
        }
    }

    // check diagonals
    int i = 0, j = 2;
    if (board[i][i] == board[i+1][i+1] && board[i+1][i+1] == board[i+2][i+2]) {
        return true;
    }

    if (board[i][j] == board[i+1][j-1] && board[i+1][j-1] == board[i+2][j-2]) {
        return true;
    }

    return false;
}

bool BOARD::update(int position){
    if(position < 1 || position > 9) {
        return false;
    }
    int i = (position - 1) / BOARD_SIZE;
    int j = (position - 1) % BOARD_SIZE;
    if(board[i][j] == 'X' || board[i][j] == 'O') {
        return false;
    }
    board[i][j] = mark;
    mark = (mark == 'X') ? 'O' : 'X';
    return true;
}