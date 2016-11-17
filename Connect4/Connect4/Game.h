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
	void takeTurn();
	bool checkWin(Board & board);
	bool checkFour(Disc board[][7], int loc, int type, int a, int b, int c, int d);

	int horizontalCheck(Board &board);

	int verticalCheck(Board &board);

	int diagonalCheck(Board &board);
	
	
private:
	Player player;
	Computer computer;
	int turn;
	Board board;
};
