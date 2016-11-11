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
	void deleteDisc(int move);
	int Evaluate(char Compare);
	int AlphaBeta(int depth, int alpha, int beta);
	int IsWin();

};

