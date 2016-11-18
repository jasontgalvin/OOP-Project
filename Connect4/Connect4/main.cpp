#include "UserInterface.h"
#include "Game.h"


int main() {
	UserInterface *ui = new UserInterface();
	Game *game = new Game();
	ui->displayStartup();
	string input = "";
	int isFirstTime = 1;

	//(input != "1") && (input != "2") && (input != "3") && (input != "4")
	while (input != "5")
	{
		if (isFirstTime != 1) {
			ui->displayStartup();
		}

		input = "";
		cin >> input;
		if (input == "1")
		{
			//START GAME
			isFirstTime++;
			cout << "Input Name: " << endl;
			cin >> input;
			game->getPlayer().setName(input);

			/*
			while(1){
				game->takeTurn();
			}
			*/
			

			while ((game->checkWin(game->getBoard()) != true)) {
				game->takeTurn();
			}

			int turn = game->getTurn();
			cout <<"turn:"<< turn;

			if (turn % 2 == 0) {

				ui->displayWinner('1');
				game->setTurn(1);
				game->resetEmpty();

			}
			else {
				ui->displayWinner('2');
				game->setTurn(1);
				game->resetEmpty();
			}


		}
		else if (input == "2")
		{
			//VIEW SCORES
			cout << game->getPlayer().getName() << "'s score is: " << game->getPlayer().getScore() << endl;

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