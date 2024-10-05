#include "..\TicTacToe (LAB1)\TicTacToe.h"

	vector<vector<char>> grid;
	bool player;
	int size;

	bool TicTacToe::HorizontalCheckWin(int x, TicTacToe& game, char value) const {
		for (int i = 0; i < size - 2;i++) {
			if (game[x][i] == value && game[x][i + 1] == value && game[x][i + 2] == value) {
				return true;
			}
		}
		return false;
	}
	bool TicTacToe::VerticalCheckWin(int y, TicTacToe& game, char value) const {
		for (int i = 0; i < size - 2;i++) {
			if (game[i][y] == value && game[i + 1][y] == value && game[i + 2][y] == value) {
				return true;
			}
		}
		return false;
	}
	bool TicTacToe::DiagonalCheckWinLR(int x, int y, TicTacToe& game, char value) const {
		if (x <= y) {
			while (x != 0) {
				x--;
				y--;
			}
		}
		else {
			while (y != 0) {
				x--;
				y--;
			}
		}
		if ((x == 0 && y >= size - 2) || (y == 0 && x >= size - 2)) {
			return false;
		}
		int lastX = size - 1 - y;
		int lastY = size - 1 - x;
		while (x != lastX - 1 && y != lastY - 1) {
			if (game[x][y] == value && game[x + 1][y + 1] == value && game[x + 2][y + 2] == value) {
				return true;
			}
			x++;
			y++;
		}
		return false;
	}
	bool TicTacToe::DiagonalCheckWinRL(int x, int y, TicTacToe& game, char value) const {

		if (x + y <= size - 1) {
			while (x != 0) {
				x--;
				y++;
			}
		}
		else {
			while (y != size - 1) {
				x--;
				y++;
			}
		}
		if ((x == 0 && y <= 1) || (y == size - 1 && x >= size - 2)) {
			return false;
		}
		int lastX = y;
		int lastY = x;
		while (x != lastX - 1 && y != lastY + 1) {
			if (game[x][y] == value && game[x + 1][y - 1] == value && game[x + 2][y - 2] == value) {
				return true;
			}
			x++;
			y--;
		}
		return false;
	}
	void TicTacToe::DrawFiller() {
		cout << "   +";
		for (int k = 0; k < size; ++k) {
			cout << "---+";
		}
		cout << endl;
	}

	TicTacToe::TicTacToe(int size) {
		if (size < 3 || size > 26) {
			size = 3;
		}
		this->player = true;
		this->size = size;
		this->grid = vector<vector<char>>(size, vector<char>(size, '#'));
	}
	void TicTacToe::DrawGrid() {
		system("cls");
		cout << "   ";
		for (int i = 0; i < size;i++) {
			cout << setw(3) << i + 1 << ' ';
		}
		cout << '\n';
		for (int i = 0; i < size;i++) {
			DrawFiller();
			cout << ' ' << char(65 + i) << ' ';
			for (int j = 0; j < size; j++) {
				cout << "| " << this->grid[i][j] << ' ';
			}
			cout << "| " << '\n';
		}
		DrawFiller();
	}
	void TicTacToe::SetValue(int x, int y, bool player) {
		if (x >= size || x < 0 || y < 0 || y >= size) {
			cout << "No such position, reenter coordinates" << '\n';
			return;
		}
		if (GetValue(x, y) == '#') {
			if (player) {
				grid[x][y] = 'x';
				this->player = false;
			}
			else {
				grid[x][y] = 'o';
				this->player = true;
			}
		}
		else {
			cout << "Cannot set value in this position" << '\n';
			return;
		}
	}
	char TicTacToe::GetValue(int x, int y) const {
		return grid[x][y];
	}
	int TicTacToe::GetSize() const {
		return this->size;
	};
	bool TicTacToe::GetPlayer() const {
		return this->player;
	}
	vector<char>& TicTacToe::operator[](int index) {
		return grid[index];
	}
	bool TicTacToe::CheckWin(int x, int y, TicTacToe& game, bool player) const {
		char value;
		if (player) {
			value = 'x';
		}
		else {
			value = 'o';
		}
		if (HorizontalCheckWin(x, game, value)) {
			return true;
		}
		else if (VerticalCheckWin(y, game, value)) {
			return true;
		}
		else if (DiagonalCheckWinLR(x, y, game, value)) {
			return true;
		}
		else if (DiagonalCheckWinRL(x, y, game, value)) {
			return true;
		}
		else return false;
	}
	void TicTacToe::WinAnnounce() const {
		if (!this->player)
			cout << "Player 1 won!";
		else cout << "Player 2 won!";
		return;
	}
