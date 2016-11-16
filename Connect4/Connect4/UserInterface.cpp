#include "UserInterface.h"
#include <iostream>
#include <stdlib.h>
#include "Player.h"
#include "Board.h"
#include "Game.h"
#include "Computer.h"
using namespace std;



UserInterface::UserInterface()
{
}


UserInterface::~UserInterface()
{
}

void UserInterface::displayStartup()
{
	string input = "";
	cout << "Welcome to Connect 4 " << endl;
	cout << "Please select an option " << endl;
	cout << "1. Start Game\n2. View Scores\n3. Quit" << endl;	//Ive included a View Scores option, this can easily be removed if we dont have the time

}
void UserInterface::displayWinner(Disc disc)
{
	//This if statement will simply check who's disc was passed in
	//But its still early to tell how exactly we can tell who's disc it is
	if (disc.getDiscType() == '1')
	{
		cout << "Player 1 is the winner!" << endl;
	}
	else
	{
		cout << "Computer is the winnter!" << endl;
	}

}
void UserInterface::displayInvalidMove()
{
	cout << "Error, invalid move. Please make a valid move" << endl;
}

