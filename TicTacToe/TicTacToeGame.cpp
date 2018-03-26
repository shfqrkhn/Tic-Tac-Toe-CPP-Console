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
	//system("cls");
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

	int turn = 0;

	while (isDone == false) {
		
		printBoard();
		
		x = getXCoord();
		y = getYCoord();
		
		if (placeMarker(x, y, currentPlayer) == false) {
			cout << "That spot is occupied\n";
		}
		else {
			turn++;
			if (checkForVictory() == true) {
				cout << currentPlayer << " won!\n";
				isDone = true;
			}
			else if (turn == 9) {
				cout << "The game is a draw\n";
				isDone = true;
			}
			//Switch players
			if (currentPlayer == player1) {
				//cout << endl<< player2 << "\'s " << "turn\n";
				currentPlayer = player2;
			}
			else {
				currentPlayer = player1;
				//cout << endl << player1 << "\'s " << "turn\n";
			}
		}
		
		
	}
}

int TicTacToeGame::getXCoord()
{
	bool isInputBad = true;

	int x;

	while (isInputBad == true) {
		cout << "Enter to x-coordiante: ";
		cin >> x;

		if (x < 1 || x>3) {
			cout << "Invalid coordinate\n";
		}
		else {
			isInputBad = false;
		}
	 }
	
	return x-1;
}

int TicTacToeGame::getYCoord()
{
	bool isInputBad = true;

	int y;

	while (isInputBad == true) {
		cout << "Enter to y-coordiante: ";
		cin >> y;

		if (y < 1 || y>3) {
			cout << "Invalid coordinate\n";
		}
		else {
			isInputBad = false;
		}
	}

	return y - 1;
}

bool TicTacToeGame::placeMarker(int x, int y, char currentPlayer) 
{
	if (board[y][x] != ' ') {
		return false;
	}
	board[y][x] = currentPlayer;
	return true;
}

bool TicTacToeGame::checkForVictory()
{
	//check rows
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return true;
		}
	}

	//check columns
	for (int i = 0; i < 3; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
			return true;
		}
	}

	//check diagonals
	for (int i = 0; i < 3; i++) {
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
			return true;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][0] != ' ') {
			return true;
		}
	}
	return false;
}