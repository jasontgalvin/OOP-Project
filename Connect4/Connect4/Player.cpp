#include "Player.h"
#include <iostream>


Player::Player()
{
	score = 0;
}


Player::~Player()
{
}



int Player::getScore()
{
	return score;
}

string Player::getName()
{
	return name;
}

Disc Player::getDisc()
{
	return disc;
}

void Player::setScore(int score)
{
	this->score = score;
}

void Player::setName(string name)
{
	this->name = name;
}

void Player::setDisc(Disc & disc)
{
	this->disc = disc;
}

void Player::takeTurn(Board &board)
{
	board.displayBoard();
	int input;
	cout << "Enter the number of which column you want to drop a disc into." << endl;
	while (cin >> input && input != NULL) {
		if (board.legalMove(--input)) {
			board.addDisc(input, '1');
		}
		else {
			cout << "That's an illegal move." << endl;
		}
	}
}