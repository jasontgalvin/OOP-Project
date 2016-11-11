#include "Board.h"
#include<iostream>

#define Situation_Win 5000 
#define Situation_DoubleThree 1800
#define Situation_Three 1000
#define Situation_DieThree 500
#define Situation_DiedThree 20
#define Situation_Two 20
#define Situation_DieTwo 10
#define Situation_DiedTwo 7
#define Situation_Lose -2999
#define TypeNumber 9 
#define Board_Horizontal 6 
#define Board_Vertical 7
#define Board_Empty '-'

using namespace std;

int TypeNum[TypeNumber];//array of all the type of situation like 1 Disc;2 Disc;3 Disc left/right note:see constant above
int Best_Move;// the result colomn computer decide to add Disc


Board::Board()
{
	//nothing to initialize here because Board::board is an array of Disc, Disc will initialize itself to '-'
}

Board::~Board()
{
}


Disc * Board::getBoard()
{
	return *board;
}


bool Board::isFull()//to see the whole board full or not(legalMove() is for checking the vertical is full or not when adding Disc)
{
	for (int i = 0; i<7; i++) {
		if (board[0][i].getDiscType() == '-') {
			return false;
		}
	}
	return true;
}

bool Board::legalMove(int move)
{
	if (move >= 0 && move <= 6) {  //Vertical is 7

		if (board[0][move].getDiscType() == '-') {//to confirm this vertical is not full
			return true;
		}
		else {
			cout << "illegal move because the vertical is full\n";
			return false;
		}
	}
	else {
		cout << "illegal move\n";
		return false;
	}

}

void Board::displayBoard()
{
	for (int i = 0; i<6; i++)//Horizontal
	{
		for (int j = 0; j<7; j++)//Vertical
			cout << board[i][j].getDiscType() << " ";
		cout << endl;
	}
}

void Board::addDisc(int move, char playerType) //the type of Disc for player1 is '1',for player2 or computer is '2'
{


	/*
	if(legalMove(move)){
	int i=1;
	while(board[i][move].getDiscType()=='-'){
	i++;
	}
	board[i-1][move].setDiscType(playerType);
	}
	*/

	int i = 1;
	while (board[i][move].getDiscType() == '-') {
		i++;
	}
	board[i - 1][move].setDiscType(playerType);

}

void Board::deleteDisc(int move) //used in AI evaluation test
{
	int i = 1;
	while (board[i][move].getDiscType() == '-') {
		i++;
	}
	board[i][move].setDiscType('-');
}

void TypeNumInit(void) //type array initialization

{
	for (int i = 0; i<TypeNumber; i++)
		TypeNum[i] = 0;
}
void TypeNumSet(void) //get the chain of Disc

{
	TypeNum[0] = TypeNum[0] / 4;
	TypeNum[2] = TypeNum[2] / 3;
	TypeNum[3] = TypeNum[3] / 3;
	TypeNum[4] = TypeNum[4] / 3;
	TypeNum[5] = TypeNum[5] / 2;
	TypeNum[6] = TypeNum[6] / 2;
	TypeNum[7] = TypeNum[7] / 2;
	while (TypeNum[2]>1)
	{
		TypeNum[2] -= 2;
		TypeNum[1] += 1;
	}
}




int CountScore(void) // get Score for evaluation

{
	int Score = 0;

	Score += (TypeNum[0] * Situation_Win);
	Score += (TypeNum[1] * Situation_DoubleThree);
	Score += (TypeNum[2] * Situation_Three);
	Score += (TypeNum[3] * Situation_DieThree);
	Score += (TypeNum[4] * Situation_DiedThree);
	Score += (TypeNum[5] * Situation_Two);
	Score += (TypeNum[6] * Situation_DieTwo);
	Score += (TypeNum[7] * Situation_DiedTwo);
	Score += (TypeNum[8] * Situation_Lose);
	return Score;
}

int Board::Evaluate(char Compare) //evaluation function used in Alphabeta prunning

{
	int Count_Left = 1;
	int Count_Right = 1;

	TypeNumInit();


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j<(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i][j - Count_Left].getDiscType() == Compare)
				Count_Left++;
			while (board[i][j + Count_Right].getDiscType() == Compare)
				Count_Right++;
			if ((Count_Left + Count_Right) == 3)
			{
				if ((board[i][j - Count_Left - 1].getDiscType() != Board_Empty) && (board[i][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[7]++;
				else if ((board[i][j - Count_Left - 1].getDiscType() != Board_Empty) || (board[i][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[6]++;
				else
					TypeNum[5]++;
			}
			else if ((Count_Left + Count_Right) == 4)
			{
				if ((board[i][j - Count_Left - 1].getDiscType() != Board_Empty) && (board[i][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[4]++;
				else if ((board[i][j - Count_Left - 1].getDiscType() != Board_Empty) || (board[i][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[3]++;
				else
					TypeNum[2]++;
			}
			else if ((Count_Left + Count_Right) >= 5)
				TypeNum[0]++;

			Count_Left = 1;
			Count_Right = 1;
		}


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j<(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i + Count_Left][j].getDiscType() == Compare)
				Count_Left++;
			while (board[i - Count_Right][j].getDiscType() == Compare)
				Count_Right++;
			if ((Count_Left + Count_Right) == 3)
			{
				if ((board[i + Count_Left + 1][j].getDiscType() != Board_Empty) && (board[i - Count_Right - 1][j].getDiscType() != Board_Empty))
					TypeNum[7]++;
				else if ((board[i + Count_Left + 1][j].getDiscType() != Board_Empty) || (board[i - Count_Right - 1][j].getDiscType() != Board_Empty))
					TypeNum[6]++;
				else TypeNum[5]++;
			}
			else if ((Count_Left + Count_Right) == 4)
			{
				if ((board[i + Count_Left + 1][j].getDiscType() != Board_Empty) && (board[i - Count_Right - 1][j].getDiscType() != Board_Empty))
					TypeNum[4]++;
				else if ((board[i + Count_Left + 1][j].getDiscType() != Board_Empty) || (board[i - Count_Right - 1][j].getDiscType() != Board_Empty))
					TypeNum[3]++;
				else
					TypeNum[2]++;
			}
			else if ((Count_Left + Count_Right) >= 5)
				TypeNum[0]++;

			Count_Left = 1;
			Count_Right = 1;
		}


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j <(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i - Count_Left][j - Count_Left].getDiscType() == Compare)
				Count_Left++;
			while (board[i + Count_Right][j + Count_Right].getDiscType() == Compare)
				Count_Right++;
			if ((Count_Left + Count_Right) == 3)
			{
				if ((board[i - Count_Left - 1][j - Count_Left - 1].getDiscType() != Board_Empty) && (board[i + Count_Right + 1][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[7]++;
				else if ((board[i - Count_Left - 1][j - Count_Left - 1].getDiscType() != Board_Empty) || (board[i + Count_Right + 1][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[6]++;
				else
					TypeNum[5]++;
			}
			else if ((Count_Left + Count_Right) == 4)
			{
				if ((board[i - Count_Left - 1][j - Count_Left - 1].getDiscType() != Board_Empty) && (board[i + Count_Right + 1][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[4]++;
				else if ((board[i - Count_Left - 1][j - Count_Left - 1].getDiscType() != Board_Empty) || (board[i + Count_Right + 1][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[3]++;
				else
					TypeNum[2]++;
			}
			else if ((Count_Left + Count_Right) >= 5)
				TypeNum[0]++;

			Count_Left = 1;
			Count_Right = 1;
		}


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j <(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i + Count_Left][j - Count_Left].getDiscType() == Compare)
				Count_Left++;
			while (board[i - Count_Right][j + Count_Right].getDiscType() == Compare)
				Count_Right++;
			if ((Count_Left + Count_Right) == 3)
			{
				if ((board[i + Count_Left + 1][j - Count_Left - 1].getDiscType() != Board_Empty) && (board[i - Count_Right - 1][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[7]++;
				else if ((board[i + Count_Left + 1][j - Count_Left - 1].getDiscType() != Board_Empty) || (board[i - Count_Right - 1][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[6]++;
				else
					TypeNum[5]++;
			}
			else if ((Count_Left + Count_Right) == 4)
			{
				if ((board[i + Count_Left + 1][j - Count_Left - 1].getDiscType() != Board_Empty) && (board[i - Count_Right - 1][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[4]++;
				else if ((board[i + Count_Left + 1][j - Count_Left - 1].getDiscType() != Board_Empty) || (board[i - Count_Right - 1][j + Count_Right + 1].getDiscType() != Board_Empty))
					TypeNum[3]++;
				else
					TypeNum[2]++;
			}
			else if ((Count_Left + Count_Right) >= 5)
				TypeNum[0]++;

			Count_Left = 1;
			Count_Right = 1;
		}

	if (Compare == '2')
		Compare = '1';
	else
		Compare = '2';

	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j<(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i][j - Count_Left].getDiscType() == Compare)
				Count_Left++;
			while (board[i][j + Count_Right].getDiscType() == Compare)
				Count_Right++;

			if ((Count_Left + Count_Right) >= 5)
				TypeNum[8]++;
			Count_Left = 1;
			Count_Right = 1;
		}


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j<(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i + Count_Left][j].getDiscType() == Compare)
				Count_Left++;
			while (board[i - Count_Right][j].getDiscType() == Compare)
				Count_Right++;

			if ((Count_Left + Count_Right) >= 5)
				TypeNum[8]++;
			Count_Left = 1;
			Count_Right = 1;
		}


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j <(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i - Count_Left][j - Count_Left].getDiscType() == Compare)
				Count_Left++;
			while (board[i + Count_Right][j + Count_Right].getDiscType() == Compare)
				Count_Right++;

			if ((Count_Left + Count_Right) >= 5)
				TypeNum[8]++;
			Count_Left = 1;
			Count_Right = 1;
		}

	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j <(Board_Vertical + 1); j++)


		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i + Count_Left][j - Count_Left].getDiscType() == Compare)
				Count_Left++;
			while (board[i - Count_Right][j + Count_Right].getDiscType() == Compare)
				Count_Right++;
			if ((Count_Left + Count_Right) >= 5)
				TypeNum[8]++;
			Count_Left = 1;
			Count_Right = 1;
		}
	TypeNumSet();
	return CountScore();
}





int Board::IsWin() // used by AI to stop human player when human player is going to win
{
	char Compare = '1';
	int Count_Left = 1;
	int Count_Right = 1;

	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j<(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i][j - Count_Left].getDiscType() == Compare)
				Count_Left++;
			while (board[i][j + Count_Right].getDiscType() == Compare)
				Count_Right++;

			if ((Count_Left + Count_Right) >= 5)
				return '1';
			Count_Left = 1;
			Count_Right = 1;
		}


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j<(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i + Count_Left][j].getDiscType() == Compare)
				Count_Left++;
			while (board[i - Count_Right][j].getDiscType() == Compare)
				Count_Right++;

			if ((Count_Left + Count_Right) >= 5)
				return '1';
			Count_Left = 1;
			Count_Right = 1;
		}


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j <(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i - Count_Left][j - Count_Left].getDiscType() == Compare)
				Count_Left++;
			while (board[i + Count_Right][j + Count_Right].getDiscType() == Compare)
				Count_Right++;

			if ((Count_Left + Count_Right) >= 5)
				return '1';
			Count_Left = 1;
			Count_Right = 1;
		}


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j <(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i + Count_Left][j - Count_Left].getDiscType() == Compare)
				Count_Left++;


			while (board[i - Count_Right][j + Count_Right].getDiscType() == Compare)
				Count_Right++;
			if ((Count_Left + Count_Right) >= 5)
				return '1';
			Count_Left = 1;
			Count_Right = 1;
		}

	Compare = '2';

	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j<(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i][j - Count_Left].getDiscType() == Compare)
				Count_Left++;
			while (board[i][j + Count_Right].getDiscType() == Compare)
				Count_Right++;

			if ((Count_Left + Count_Right) >= 5)
				return '2';
			Count_Left = 1;
			Count_Right = 1;
		}


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j<(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i + Count_Left][j].getDiscType() == Compare)
				Count_Left++;
			while (board[i - Count_Right][j].getDiscType() == Compare)
				Count_Right++;

			if ((Count_Left + Count_Right) >= 5)
				return '2';
			Count_Left = 1;
			Count_Right = 1;
		}


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j <(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i - Count_Left][j - Count_Left].getDiscType() == Compare)
				Count_Left++;
			while (board[i + Count_Right][j + Count_Right].getDiscType() == Compare)
				Count_Right++;

			if ((Count_Left + Count_Right) >= 5)
				return '2';
			Count_Left = 1;
			Count_Right = 1;
		}


	for (int i = 1; i<(Board_Horizontal + 1); i++)
		for (int j = 1; j <(Board_Vertical + 1); j++)
		{
			if (board[i][j].getDiscType() != Compare)
				continue;
			while (board[i + Count_Left][j - Count_Left].getDiscType() == Compare)
				Count_Left++;
			while (board[i - Count_Right][j + Count_Right].getDiscType() == Compare)
				Count_Right++;
			if ((Count_Left + Count_Right) >= 5)
				return '2';
			Count_Left = 1;
			Count_Right = 1;
		}
	return 0;
}





int Board::AlphaBeta(int depth, int alpha, int beta) // Alphabeta prunning algorithm for AI
{
	int Level = 1;
	int val;
	char Compare;

	if ((Level % 2) == 1)
		Compare = '2';
	else
		Compare = '1';

	if ((depth <= 0) || (IsWin()))
		return Evaluate(Compare);
	for (int i = 0; i<Board_Vertical; i++)
	{
		if (board[1][i + 1].getDiscType() != Board_Empty)
			continue;
		addDisc(i + 1, Compare);
		Level++;
		val = -AlphaBeta(depth - 1, -beta, -alpha);
		deleteDisc(i + 1);
		Level--;
		if (val >= beta)
			return beta;
		if (val>alpha)
		{
			alpha = val;
			if (depth == 7)
			{
				Best_Move = i + 1;
			}
		}
	}
	return alpha;
}