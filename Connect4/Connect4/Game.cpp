#include "Game.h"

Game::Game()
{
	turn = 0;
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
