#include "Game.h"
#include "Disc.h"
#include "Player.h"
#include "Computer.h"
#include <iostream>
#define BOARD_ROWS 6
#define BOARD_COLS 7
using namespace std;

Game::Game()
{
	turn = 1;
}


Game::~Game()
{
}

Player Game::getPlayer()
{
	return player;
}

Computer Game::getComputer()
{
	return computer;
}

int Game::getTurn()
{
	return turn;
}

Board Game::getBoard()
{
	return board;
}

void Game::setPlayer(Player & player)
{
	this->player = player;
}

void Game::setComputer(Computer & computer)
{
	this->computer = computer;
}

void Game::setTurn(int turn)
{
	this->turn = turn;
}

void Game::setBoard(Board & board)
{
	this->board = board;
}

void Game::takeTurn()
{
	//player starts first
	//check if turn is an even or odd number

		if (turn % 2 != 0)
		{
			player.takeTurn(board);
			turn++;
		}
		else
		{
			computer.takeTurn(board);
			turn++;
		}
	
	
}

bool Game::checkWin(Board &board)
{
	/*
	cout << endl << endl << endl << endl;
	cout << horizontalCheck(board);
	cout << verticalCheck(board);
	cout << diagonalCheck(board);
	cout << endl << endl << endl << endl;
	*/

	return (horizontalCheck(board) || verticalCheck(board) || diagonalCheck(board));
}

//THIS IS WHERE THINGS ARE BROKEN AND I CANT FIGURE OUT WHY part 2, electric boogaloo
bool Game::checkFour(Disc board[][7], int loc, int check,  int a, int b, int c, int d) {
	if (check == 0) { //horizintal checking

		/*
		cout << (board[a][loc].getDiscType() != '-');
		cout << (board[a][loc].getDiscType() == board[b][loc].getDiscType());
		cout << (board[b][loc].getDiscType() == board[c][loc].getDiscType());
		cout << (board[c][loc].getDiscType() == board[d][loc].getDiscType());
		cout << endl;
		
		board[a][loc].getDiscType() == '-' && board[a][loc].getDiscType() == board[b][loc].getDiscType() &&
			board[b][loc].getDiscType() == board[c][loc].getDiscType() &&
			board[c][loc].getDiscType() == board[d][loc].getDiscType() 
		*/
		return (board[loc][a].getDiscType() != '-' && board[loc][a].getDiscType() == board[loc][b].getDiscType() &&
			board[loc][b].getDiscType() == board[loc][c].getDiscType() &&
			board[loc][c].getDiscType() == board[loc][d].getDiscType());
	}
	else if (check == 1) { //vertical checking

		/*
		cout << (board[a][loc].getDiscType() != '-');
		cout << (board[a][loc].getDiscType() == board[b][loc].getDiscType());
		cout << (board[b][loc].getDiscType() == board[c][loc].getDiscType());
		cout << (board[c][loc].getDiscType() == board[d][loc].getDiscType());
		cout << endl;
		*/

		return (board[a][loc].getDiscType() != '-' && board[a][loc].getDiscType() == board[b][loc].getDiscType() &&
			board[b][loc].getDiscType() == board[c][loc].getDiscType() &&
			board[c][loc].getDiscType() == board[d][loc].getDiscType());

	}

	else if (check == 2) { //diagonal checking

		/*
		cout << (board[loc][a].getDiscType() != '-');
		cout << (board[loc][a].getDiscType() == board[loc+b][a+b].getDiscType());
		cout << (board[loc+b][a+b].getDiscType() == board[loc+c][a+c].getDiscType());
		cout << (board[loc+d][a+d].getDiscType() == board[loc+d][a+d].getDiscType());
		cout << endl;
		*/
		
		
		
		return ((board[loc][a].getDiscType() != '-') && board[loc][a].getDiscType() == board[loc + b][a + b].getDiscType() &&
			board[loc + b][a + b].getDiscType() == board[loc + c][a + c].getDiscType() &&
			board[loc + c][a + c].getDiscType() == board[loc + d][a + d].getDiscType());

	}

	else if (check == 3) {

		/*
		cout << (board[loc][a].getDiscType() != '-');
		cout << (board[loc][a].getDiscType() == board[loc - b][a + b].getDiscType());
		cout << (board[loc - b][a + b].getDiscType() == board[loc - c][a + c].getDiscType());
		cout << (board[loc - d][a + d].getDiscType() == board[loc - d][a + d].getDiscType());
		cout << endl;
		*/

		return ((board[loc][a].getDiscType() != '-') && board[loc][a].getDiscType() == board[loc - b][a + b].getDiscType() &&
			board[loc - b][a + b].getDiscType() == board[loc - c][a + c].getDiscType() &&
			board[loc - c][a + c].getDiscType() == board[loc - d][a + d].getDiscType());
	}

	else
	{
		return false;
	}

}

//Check the board horizontally
//call check4 method which will for a given column, check and index, then check the next 3 indices next to its right
int Game::horizontalCheck(Board &board) {
	int row, col, idx;
	const int WIDTH = 1;

	for (row = 0; row < BOARD_ROWS; row++) {
		for (col = 0; col < BOARD_COLS - 3; col++) {
			idx = col;
			if (checkFour(board.board,row, 0, idx, idx + WIDTH, idx + WIDTH * 2, idx + WIDTH * 3)) {
				return 1;
			}
		}
	}
	return 0;

}

//same idea applies to this one
int Game::verticalCheck(Board &board) {
	int row, col, idx;
	const int HEIGHT = 7;

	for (row = 0; row < BOARD_ROWS - 3; row++) {
		for (col = 0; col < BOARD_COLS; col++) {
			idx = row;
			if (checkFour(board.board, col, 1, idx, idx + 1, idx +  2, idx + 3)) { //need the column to check
				return 1;
			}
		}
	}
	return 0;

}
int Game::diagonalCheck(Board &board) {
	int row, col, idx, count = 0;
	const int DIAG_RGT = 6, DIAG_LFT = 8;

	for (row = 0; row < BOARD_ROWS; row++) {
		for (col = 0; col < BOARD_COLS; col++) {

			if (
				checkFour(board.board, row, 2, col, 1, 2, 3) ||
				checkFour(board.board, row, 2, col, -1, -2, -3)||
				checkFour(board.board, row, 3, col, 1, 2, 3)||
				checkFour(board.board, row, 3, col, -1, -2, -3)) 
			{
				return 1;
			}
			count++;
		}
		count = 0;
	}
	return 0;

}

void Game::resetEmpty() {
	char playerType = '-';

	for (int i = 0; i<6; i++)//Horizontal
	{
		for (int j = 0; j < 7; j++)//Vertical
		{
			board.board[i][j].setDiscType(playerType);
		}

	}
}
