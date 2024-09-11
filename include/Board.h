#ifndef _BOARD_H_
#define _BOARD_H_

const int BOARD_SIZE = 3;
const char DIGITS[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

class BOARD {
    public:
        BOARD() = default;
        ~BOARD() = default;
        void init();
        void draw();
        bool checkWin();
        bool isFull();
        bool update(int position);
    private:
        char board[BOARD_SIZE][BOARD_SIZE];
        char mark;
};

#endif // _BOARD_H_
