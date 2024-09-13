#include "Game.h"
#include <iostream>

GAME::GAME(BOARD* board) {
    m_board = board;
}

void GAME::run(){
    m_board->init();
    int moves=0;
    while(moves<9){
        std::cout<<"\nTIC TAC TOE ! \n";
        m_board->draw();

        std::cout<<"Player "<<((moves&1) ? "2":"1")<< "'s turn"<<std::endl;

        int position;
        std::cout<<"Enter position: ";
        std::cin>>position;
        while(std::cin.fail() || position < 1 || position > 9){
            std::cin.clear(); // Clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout<<"Invalid Input.Please Enter number b/w 1 to 9.Enter again: ";
            std::cin>>position;
        }

        while(!m_board->update(position)){
            std::cout<<"Invalid Input.The number entered is already marked.Enter again: ";
            std::cin>>position; 
        }
        if(moves>3){
            if(m_board->checkWin()){
                m_board->draw();
                std::cout<<"Player "<<((moves&1) ? "2":"1")<< " wins!"<<std::endl;
                break;
            }
            if(moves==8){
                m_board->draw();
                std::cout<<"It's a draw!"<<std::endl;
                break;
            }
        }
        moves++;
    }
}