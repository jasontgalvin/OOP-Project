#include "UserInterface.h"
#include "Game.h"


int main() {
	UserInterface *ui = new UserInterface();
	Game *game = new Game();
	ui->displayStartup();
	
	while (game->checkWin(game->getBoard()) != true) {
		game->takeTurn();
	}
	
	int turn = game->getTurn();

	if (turn % 2 != 0) {
		ui->displayWinner(game->getPlayer().getDisc());
	}
	else {
		ui->displayWinner(game->getComputer().getDisc());
	}
	return 0;
}