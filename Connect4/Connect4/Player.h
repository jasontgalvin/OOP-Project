#pragma once
#include <string>
#include "Disc.h"
#include "Board.h"
using namespace std;
class Player
{
public:
	Player();
	~Player();
	void takeTurn(Board board);
	int getScore();
	string getName();
	Disc getDisc();
	void setScore(int score);
	string setName(string name);
	void setDisc(Disc &disc);
private:
	int score;
	string name;
	Disc disc;
};

