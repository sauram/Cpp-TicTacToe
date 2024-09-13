#include <gtest/gtest.h>
#include "./../include/Board.h"

struct BoardBase : public ::testing::Test {
    void SetUp(){
        m_board.init();
    }
    void TearDown(){}
    BOARD m_board;
};

TEST_F(BoardBase, ShouldInit){
    EXPECT_EQ(m_board.getMark(), 'X');
    char* board = m_board.getBoard();
    int digit = 0;
    for(int i=0;i<9;i++){
        EXPECT_EQ(board[i], DIGITS[digit]);
        digit++;
    }
}

TEST_F(BoardBase, ShouldDraw){
    std::string expected;
    expected = "-  -  -  -  - \n";
    expected+= "| 1 | 2 | 3 | \n";
    expected+= "-  -  -  -  - \n";
    expected+= "| 4 | 5 | 6 | \n";
    expected+= "-  -  -  -  - \n";
    expected+= "| 7 | 8 | 9 | \n";
    expected+= "-  -  -  -  - \n";
    testing::internal::CaptureStdout();
    m_board.draw();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, expected);
}

TEST_F(BoardBase, ShouldUpdate){
    std::string expected;
    expected = "-  -  -  -  - \n";
    expected+= "| 1 | 2 | 3 | \n";
    expected+= "-  -  -  -  - \n";
    expected+= "| 4 | X | 6 | \n";
    expected+= "-  -  -  -  - \n";
    expected+= "| 7 | 8 | 9 | \n";
    expected+= "-  -  -  -  - \n";

    EXPECT_EQ(m_board.getMark(), 'X');

    m_board.update(5);
    EXPECT_EQ(m_board.getMark(), 'O');

    testing::internal::CaptureStdout();
    m_board.draw();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, expected);
}

TEST_F(BoardBase, ShouldCheckWinForRows){
    m_board.update(1);
    m_board.update(4);
    m_board.update(2);
    m_board.update(5);
    m_board.update(3);
    EXPECT_TRUE(m_board.checkWin());

}

TEST_F(BoardBase, ShouldCheckWinForColumns){
    m_board.update(1);
    m_board.update(2);
    m_board.update(4);
    m_board.update(5);
    m_board.update(7);
    EXPECT_TRUE(m_board.checkWin());
}

TEST_F(BoardBase, ShouldCheckWinForDiagonals){
    m_board.update(1);
    m_board.update(2);
    m_board.update(5);
    m_board.update(4);
    m_board.update(9);
    EXPECT_TRUE(m_board.checkWin());
}
