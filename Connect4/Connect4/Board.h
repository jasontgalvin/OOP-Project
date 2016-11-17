#pragma once
#include "Disc.h"
class Board
{
private:
	
	
	int Best_Move = 0;// the result colomn computer decide to add Disc
	int x;

public:
	Board();
	~Board();
	Disc board[6][7];
	Disc *getBoard(); //get the array
	//void setBoard(int &board); Tricky and not needed
	int TypeNum[9];//array of all the type of situation like 1 Disc;2 Disc;3 Disc left/right note:see constant above
	bool isFull();
	bool legalMove(int move);
	void displayBoard();
	void addDisc(int move, char playerType);
	void deleteDisc(int move);
	int Evaluate(char Compare);
	int AlphaBeta(int depth, int alpha, int beta);
	int IsWin();
	int getBestMove();
	void TypeNumInit(void);
	void TypeNumSet(void);
	int CountScore(void);

};

