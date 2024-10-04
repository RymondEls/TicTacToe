#include "pch.h"
#include "../../TicTacToe (LAB1)/TicTacToe (LAB1)/TicTacToe.cpp"

TEST(TicTacToeTest, CheckWinHorizontal) {
    TicTacToe game(3);
    game.SetValue(0, 0, true);
    game.SetValue(0, 1, true);
    game.SetValue(0, 2, true);
    ASSERT_TRUE(game.CheckWin(0, 2, game, true));
}

TEST(TicTacToeTest, CheckWinVertical) {
    TicTacToe game(3);
    game.SetValue(0, 0, false);
    game.SetValue(1, 0, false);
    game.SetValue(2, 0, false);
    ASSERT_TRUE(game.CheckWin(2, 0, game, false));
}

TEST(TicTacToeTest, CheckWinDiagonalLRX) {
    TicTacToe game(3);
    game.SetValue(0, 0, true);
    game.SetValue(1, 1, true);
    game.SetValue(2, 2, true);
    ASSERT_TRUE(game.CheckWin(2, 2, game, true));
}

TEST(TicTacToeTest, CheckWinDiagonalRLX) {
    TicTacToe game(3);
    game.SetValue(0, 2, true);
    game.SetValue(1, 1, true);
    game.SetValue(2, 0, true);
    ASSERT_TRUE(game.CheckWin(2, 0, game, true));
}

TEST(TicTacToeTest, GetOutOfRangeSize) {
    TicTacToe game(27);
    ASSERT_TRUE(game.GetSize(), 3);
}

TEST(TicTacToeTest, NoSuchPosition) {
    TicTacToe game(3);
    ASSERT_NO_FATAL_FAILURE(game.SetValue(-1, 4, true));
}

TEST(TicTacToeTest, CheckWinNoWin) {
    TicTacToe game(3);
    game.SetValue(0, 0, true);
    game.SetValue(0, 1, false);
    game.SetValue(0, 2, true);
    ASSERT_FALSE(game.CheckWin(0, 2, game, true));
}

TEST(TicTacToeTest, CheckWinDiagonalY) {
    TicTacToe game(5);
    game.SetValue(1, 0, true);
    game.SetValue(2, 1, true);
    game.SetValue(3, 2, true);
    ASSERT_TRUE(game.CheckWin(3, 2, game, true));
}

TEST(TicTacToeTest, SetValueAndGetPlayer) {
    TicTacToe game(3);
    game.SetValue(0, 0, true);
    ASSERT_EQ(game.GetPlayer(), false);
    game.SetValue(1, 1, false);
    ASSERT_EQ(game.GetPlayer(), true);
}

TEST(TicTacToeTest, DrawGridTest) {
    TicTacToe game(3);
    testing::internal::CaptureStdout();
    game.DrawGrid();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
}

TEST(TicTacToeTest, WinAnnounceTest) {
    TicTacToe game(3);
    testing::internal::CaptureStdout();
    game.WinAnnounce();
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_FALSE(output.empty());
}