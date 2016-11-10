#include "Game.h"
#include "Disc.h"
#include "Player.h"
#include <iostream>
using namespace std;

Game::Game()
{
	turn = 1;
}


Game::~Game()
{
}

Player Game::getPlayer()
{
	return player;
}

Computer Game::getComputer()
{
	return computer;
}

int Game::getTurn()
{
	return turn;
}

Board Game::getBoard()
{
	return board;
}

void Game::setPlayer(Player & player)
{
	this->player = player;
}

void Game::setComputer(Computer & computer)
{
	this->computer = computer;
}

void Game::setTurn(int turn)
{
	this->turn = turn;
}

void Game::setBoard(Board & board)
{
	this->board = board;
}

void Game::takeTurn()
{
	//player starts first
	//check if turn is an even or odd number
	if (turn % 2 != 0)
	{
		player.takeTurn(getBoard());
		checkWin(player.getDisc());
		turn++;
	}
	else
	{
		computer.takeTurn(getBoard());
		checkWin(computer.getDisc());
		turn++;
	}
}

Disc Game::checkWin(Disc & disc)
{

}
