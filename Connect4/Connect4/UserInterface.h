#pragma once
#include <string>
#include "Disc.h"
#include <iostream> // include header

using namespace std;
class UserInterface
{
public:
	UserInterface();
	~UserInterface();
	void displayStartup();
	void displayWinner(Disc disc);
	void displayInvalidMove();
};

