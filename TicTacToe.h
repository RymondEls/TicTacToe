#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class TicTacToe {
private:
	int size;
	bool player;
	vector<vector<char>> grid;
	bool HorizontalCheckWin(int, TicTacToe&, char) const;
	bool VerticalCheckWin(int, TicTacToe&, char) const;
	bool DiagonalCheckWinLR(int, int, TicTacToe&, char) const;
	bool DiagonalCheckWinRL(int, int, TicTacToe&, char) const;
	void DrawFiller();
public:
	TicTacToe(int);
	void DrawGrid();
	void SetValue(int, int, bool);
	char GetValue(int, int) const;
	bool GetPlayer() const;
	int GetSize() const;
	vector<char>& operator[](int index);
	bool CheckWin(int, int, TicTacToe&, bool) const;
	void WinAnnounce() const;
};