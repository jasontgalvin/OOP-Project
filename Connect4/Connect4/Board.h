#pragma once
#include "Disc.h"
class Board
{
private:
	Disc board[7][6];

public:
	Board();
	~Board();
	Disc* getBoard(); //get the array
	//void setBoard(int &board); Tricky and not needed
	bool isFull();
	bool legalMove();
	void displayBoard();
};

