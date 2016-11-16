#include "UserInterface.h"
#include "Game.h"


int main() {
	UserInterface *ui = new UserInterface();
	Game *game = new Game();
	ui->displayStartup();
	string input = "";
	
	while ((input != "1") && (input != "2") && (input != "3"))
	{
		cin >> input;
		if (input == "1")
		{
			//START GAME
			cout << "Input Name: " << endl;
			cin >> input;
			game->getPlayer().setName(input);

			game->takeTurn();
			game->takeTurn();
			game->takeTurn();
			game->takeTurn();
			game->takeTurn();

			/*while ((game->checkWin(game->getBoard()) != true) {
				game->takeTurn();
			}*/

			int turn = game->getTurn();

			if (turn % 2 != 0) {
				ui->displayWinner(game->getPlayer().getDisc());
			}
			else {
				ui->displayWinner(game->getComputer().getDisc());
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