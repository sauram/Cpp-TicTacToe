#ifndef _BOARD_H_
#define _BOARD_H_

const int BOARD_SIZE = 3;
const char DIGITS[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

class BOARD {
    public:
        BOARD() = default;
        virtual ~BOARD() = default;
        virtual void init();
        virtual void draw();
        virtual bool checkWin();
        virtual bool update(int position);

        virtual char* getBoard() {
            return &board[0][0];
        }
        virtual char getMark() {
            return mark;
        }

    private:
        char board[BOARD_SIZE][BOARD_SIZE];
        char mark;
};

#endif // _BOARD_H_
