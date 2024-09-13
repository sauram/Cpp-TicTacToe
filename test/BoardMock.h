#ifndef _BOARD_MOCK_H_
#define _BOARD_MOCK_H_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Board.h"

struct BoardMock : public BOARD {
    MOCK_METHOD(void, init, (), ());
    MOCK_METHOD(void, draw, ());
    MOCK_METHOD(bool, checkWin, ());
    MOCK_METHOD(bool, update, (int position));
    MOCK_METHOD(char*, getBoard, ());
    MOCK_METHOD(char, getMark, ());
};

#endif // _BOARD_MOCK_H_