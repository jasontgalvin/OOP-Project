#pragma once
#include "Player.h"

class Computer : public Player
{
public:
	Computer();
	~Computer();
	void takeTurn(Board &board);
};

