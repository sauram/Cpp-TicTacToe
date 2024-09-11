#ifndef _GAME_H
#define _GAME_H

#include "Board.h"
class GAME{
    public:
        GAME(const BOARD& board);
        ~GAME() = default;

        void run();

    private:
        BOARD m_board;
};
#endif // _GAME_H