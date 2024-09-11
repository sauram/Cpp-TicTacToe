#include "./../include/Game.h"
#include <iostream>

GAME::GAME(const BOARD& board) {
    m_board = board;
}

void GAME::run(){
    m_board.init();
    int moves=0;
    while(moves<9){
        std::cout<<"\nTIC TAC TOE ! \n";
        m_board.draw();

        std::cout<<"Player "<<((moves&1) ? "2":"1")<< "'s turn"<<std::endl;

        int position;
        std::cout<<"Enter position: ";
        std::cin>>position;
        while(position < 1 || position > 9){
            std::cout<<"Invalid Input.\nPlease Enter number b/w 1 to 9.\nEnter again: ";
            std::cin>>position;
        }

        while(!m_board.update(position)){
            std::cout<<"Invalid Input.\nThe number entered is already marked.\nEnter again: ";
            std::cin>>position;
        }
        if(moves>3){
            if(m_board.checkWin()){
                m_board.draw();
                std::cout<<"Player "<<((moves&1) ? "2":"1")<< " wins!"<<std::endl;
                break;
            }
            if(moves==8){
                m_board.draw();
                std::cout<<"It's a draw!"<<std::endl;
                break;
            }
        }
        moves++;
    }
}