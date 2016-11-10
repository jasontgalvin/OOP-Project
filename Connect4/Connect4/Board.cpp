#include "Board.h"



Board::Board()
{
}


Board::~Board()
{
}

Disc * Board::getBoard()
{
	return *board;
}


bool Board::isFull()
{
	return false;
}

bool Board::legalMove(int move)
{
	return false;
}

void Board::displayBoard()
{
}

void Board::addDisc(int move)
{
}
