#include "stdafx.h"
#include "TicTacToeGame.h"
#include <iostream>

using namespace std;

TicTacToeGame::TicTacToeGame()
{
}

void TicTacToeGame::clearBoard()
{
	for (int y = 0; y < 3; y++)	{
		for (int x = 0; x < 3; x++) {
			board[y][x] = ' ';
		}
	}
}

void TicTacToeGame::printBoard()
{
	cout << endl;
	cout << " |1|2|3|\n";
	for (int y = 0; y < 3; y++) {
		cout << "--------" << endl;
		cout << y+1 << "|" << board[y][0] << "|" << board[y][1] << "|" << board[y][2] << "|" << endl;
	}
	cout << "-------" << endl;
}

void TicTacToeGame::playGame()
{
	clearBoard();

	char player1 = 'X';
	char player2 = 'O';

	char currentPlayer = player1;
	bool isDone = false;

	int x, y;

	while (isDone == false) {
		printBoard();
		x = getXCoord();
		y = getYCoord();
		placeMarker(x, y, currentPlayer);
		
	}
}

int TicTacToeGame::getXCoord()
{
	int x;
	cout << "Enter to x-coordiante: ";
	cin >> x;
	return x-1;
}

int TicTacToeGame::getYCoord()
{
	int y;
	cout << "Enter to y-coordiante: ";
	cin >> y;
	return y-1;
}

bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer) 
{
	if (board[y][x] != ' ') {
		return false;
	}
	board[y][x] = currentPlayer;
	return true;
}