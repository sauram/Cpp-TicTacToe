#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <streambuf>
#include "./BoardMock.h"
#include "../include/Game.h"

struct GameBase : public ::testing::Test {

    GameBase(): m_game(&m_board_mock){}

    void SetUp(){}
    void TearDown(){}

    GAME m_game;
    BoardMock m_board_mock;
};

TEST_F(GameBase, GameShouldRun){
    EXPECT_CALL(m_board_mock, init()).Times(1);
    EXPECT_CALL(m_board_mock, draw()).Times(6);
    EXPECT_CALL(m_board_mock, update(::testing::_))
                        .WillOnce(::testing::Return(false))
                        .WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(m_board_mock, checkWin()).WillOnce(::testing::Return(true));

    std::streambuf* orig = std::cout.rdbuf();
    std::istringstream input("10 1 1 2 3 4 5");
    std::cin.rdbuf(input.rdbuf());

    m_game.run();
    std::cout.rdbuf(orig);
}