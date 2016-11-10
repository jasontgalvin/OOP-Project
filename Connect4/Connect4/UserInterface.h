#pragma once
#include <string>
#include "Disc.h"
#include <iostream>
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

