#pragma once
#include "Disc.h"
class Board
{
private:
	Disc board[6][7];

public:
	Board();
	~Board();
	Disc* getBoard(); //get the array
	//void setBoard(int &board); Tricky and not needed
	bool isFull();
	bool legalMove(int move);
	void displayBoard();
	void addDisc(int move, char playerType);
};

