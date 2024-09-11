#include<iostream>
#include "./../include/Board.h"
#include "./../include/Game.h"

int main() {
    BOARD board;
    GAME game(board);
    game.run();
    return 0;
}