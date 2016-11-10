#include "Board.h"
#include<iostream>
using namespace std;


Board::Board()
{
	//nothing to initialize here because Board::board is an array of Disc, Disc will initialize itself to '-'
}

Board::~Board()
{
}


Disc * Board::getBoard()
{
	return *board;
}


bool Board::isFull()//to see the whole board full or not(legalMove() is for checking the vertical is full or not when adding Disc)
{
	for (int i = 0; i<7; i++) {
		if (board[0][i].getDiscType() == '-') {
			return false;
		}
	}
	return true;
}

bool Board::legalMove(int move)
{
	if (move >= 0 && move <= 6) {  //Vertical is 7

		if (board[0][move].getDiscType() == '-') {//to confirm this vertical is not full
			return true;
		}
		else {
			cout << "illegal move because the vertical is full\n";
			return false;
		}
	}
	else {
		cout << "illegal move\n";
		return false;
	}

}

void Board::displayBoard()
{
	for (int i = 0; i<6; i++)//Horizontal
	{
		for (int j = 0; j<7; j++)//Vertical
			cout << board[i][j].getDiscType() << " ";
		cout << endl;
	}
}

void Board::addDisc(int move, char playerType) //the type of Disc for player1 is '1',for player2 or computer is '2'
{
	if (legalMove(move)) {
		int i = 1;
		while (board[i][move].getDiscType() == '-') {
			i++;
		}
		board[i-1][move].setDiscType(playerType);
	}

}