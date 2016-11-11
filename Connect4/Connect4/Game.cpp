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
		player.takeTurn(getBoard());
		checkWin(board);
		turn++;
	}
	else
	{
		computer.takeTurn(getBoard());
		checkWin(board);
		turn++;
	}
}

bool Game::checkWin(Board &board)
{
	return (horizontalCheck(board) || verticalCheck(board) || diagonalCheck(board));
}

//THIS IS WHERE THINGS ARE BROKEN AND I CANT FIGURE OUT WHY
bool Game::checkFour(Board &board, int a, int b, int c, int d) {
	if (board[a] == board[b] && board[b] == board[c] && board[c] == board[d] && board[a] != '-')
	{
		return true;
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
			idx = BOARD_COLS * row + col;
			if (checkFour(board, idx, idx + WIDTH, idx + WIDTH * 2, idx + WIDTH * 3)) {
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
			idx = BOARD_COLS * row + col;
			if (checkFour(board, idx, idx + HEIGHT, idx + HEIGHT * 2, idx + HEIGHT * 3)) {
				return 1;
			}
		}
	}
	return 0;

}
int Game::diagonalCheck(Board &board) {
	int row, col, idx, count = 0;
	const int DIAG_RGT = 6, DIAG_LFT = 8;

	for (row = 0; row < BOARD_ROWS - 3; row++) {
		for (col = 0; col < BOARD_COLS; col++) {
			idx = BOARD_COLS * row + col;
			if (count <= 3 && checkFour(board, idx, idx + DIAG_LFT, idx + DIAG_LFT * 2, idx + DIAG_LFT * 3) || count >= 3 && checkFour(board, idx, idx + DIAG_RGT, idx + DIAG_RGT * 2, idx + DIAG_RGT * 3)) {
				return 1;
			}
			count++;
		}
		count = 0;
	}
	return 0;

}
