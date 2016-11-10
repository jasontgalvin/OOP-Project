#include "Player.h"



Player::Player()
{
	score = 0;
}


Player::~Player()
{
}

void Player::takeTurn(Board board)
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

string Player::setName(string name)
{
	this->name = name;
}

void Player::setDisc(Disc & disc)
{
	this->disc = disc;
}
