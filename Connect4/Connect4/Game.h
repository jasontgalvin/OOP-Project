#include "Player.h"
#include "Computer.h"
#include "Board.h"
#include <iostream>
using namespace std;

class Game
{
public:
	Game();
	~Game();
	Player getPlayer();
	Computer getComputer();
	int getTurn();
	Board getBoard();
	void setPlayer(Player &player);
	void setComputer(Computer &computer);
	void setTurn(int turn);
	void setBoard(Board &board);
	
	
private:
	Player player;
	Computer computer;
	int turn;
	Board board;
};
