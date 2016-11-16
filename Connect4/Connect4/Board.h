#pragma once
#include "Disc.h"
class Board
{
private:
	Disc ** board;
	int TypeNum[9];//array of all the type of situation like 1 Disc;2 Disc;3 Disc left/right note:see constant above
	int Best_Move;// the result colomn computer decide to add Disc

public:
	Board();
	~Board();
	Disc** getBoard(); //get the array
	//void setBoard(int &board); Tricky and not needed
	bool isFull();
	bool legalMove(int move);
	void displayBoard();
	void addDisc(int move, char playerType);
	void deleteDisc(int move);
	int Evaluate(char Compare);
	int AlphaBeta(int depth, int alpha, int beta);
	int IsWin();
	int getBestMove();

};

