#include "Computer.h"
#include <iostream>


Computer::Computer()
{
}


Computer::~Computer()
{
}

void Computer::takeTurn(Board &board)
{
	/*
	Board b;

	b.addDisc(0, '1');
	int x = b.AlphaBeta(7, -30000, 30000);
	b.addDisc(Best_Move, '2');

	b.addDisc(0, '1');
	x = b.AlphaBeta(7, -30000, 30000);
	b.addDisc(Best_Move, '2');

	b.addDisc(0, '1');
	x = b.AlphaBeta(7, -30000, 30000);
	b.addDisc(Best_Move, '2');

	b.addDisc(1, '1');
	x = b.AlphaBeta(7, -30000, 30000);
	b.addDisc(Best_Move, '2');

	b.addDisc(0, '1');
	x = b.AlphaBeta(7, -30000, 30000);
	b.addDisc(Best_Move, '2');





	b.displayBoard();
	*/
	cout << "\ncomputer takes turn\n"<<endl;


	int x = board.AlphaBeta(7, -30000, 30000);

	if (board.getBestMove() != NULL) {

		if (1) {
			board.addDisc(board.getBestMove(),'2');
		}
		else {
			cout << "illegal computer output" << endl;
		}
		board.displayBoard();
	}
	else {
		cout << "AI empty";
	}
}
