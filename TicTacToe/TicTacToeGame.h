#pragma once
class TicTacToeGame
{
public:
	TicTacToeGame();
	void playGame();
private:
	char board[3][3];
	void clearBoard();
	void printBoard();
	int getXCoord();
	int getYCoord();
	bool placeMarker(int x, int y, char currentPlayer);
};

