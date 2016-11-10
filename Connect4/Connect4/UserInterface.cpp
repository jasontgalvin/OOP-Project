#include "UserInterface.h"
#include <iostream>
#include <stdlib.h>
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

	while ((input != "1") && (input != "2") && (input != "3"))
	{
		cin >> input;
		if (input == "1")
		{
			//START GAME
		}
		else if (input == "2")
		{
			//VIEW SCORES
		}
		else if (input == "3")
		{
			exit(0);	//Program terminates
		}
		else {
			cout << "Error, invalid input" << endl;
		}
	}

}
void UserInterface::displayWinner(Disc disc) 
{

}
void UserInterface::displayInvalidMove() {}

