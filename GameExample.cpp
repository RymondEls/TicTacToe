#include <iostream>
#include "TicTacToe.h"

using namespace std;

int main()
{
	int moveCount = 0;
	int size;
	cout << "Enter game size ( 3x3+ ): " << '\n';
	cin >> size;
	TicTacToe Game(size);
	Game.DrawGrid();
	char x;
	int y;
	for (int i = 0; i <= 4;i++) {
		cout << "Move coordinates (char-int):" << '\n';
		cin >> x >> y;
		Game.SetValue(x - 65, y - 1, Game.GetPlayer());
		system("pause");
		Game.DrawGrid();
		moveCount++;
	}
	while (x >= size+65 || x < 65 || y < 0 || y >= size) {
		cout << "No such position, reenter coordinates" << '\n';
		system("pause");
		Game.DrawGrid();
		cin >> x >> y;
	}
	while (!Game.CheckWin(x - 65, y - 1, Game, !Game.GetPlayer())) {
		if (moveCount == Game.GetSize() * Game.GetSize()) {
			break;
		}
		cin >> x >> y;
		Game.SetValue(x - 65, y - 1, Game.GetPlayer());
		system("pause");
		Game.DrawGrid();
		moveCount++;
	}
	if (Game.CheckWin( x - 65, y - 1, Game, !Game.GetPlayer()))
		Game.WinAnnounce();
	else
		cout << "Draw.";
	return 0;
}
