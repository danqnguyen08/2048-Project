#include <iostream>
#include <random>
#include <iomanip>
using namespace std;

void move_left(int board[][5], int numrows = 5)
{
	//CODE HERE
	for (int r = 0; r < numrows; r++)
	{
		//Step 1: slide non-zero tiles to the left
		int temp[5] = {0,0,0,0,0};
		int pos = 0;
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] != 0)
			{
				temp[pos] = board[r][c];
				pos++;
			}
		}

		//Step 2: merge equal neighbors (each tile merges at most once)
		for (int i = 0; i < 4; i++)
		{
			if (temp[i] != 0 && temp[i] == temp[i + 1])
			{
				temp[i] = temp[i] * 2;
				temp[i + 1] = 0;
				i++;	//skips the tile we jsut merged into
			}
		}
		//Step 3: slide again to close gaps, writing back to the board
		pos = 0;
		for (int c = 0; c < 5; c++)
		{
			board[r][c] = 0;
		}
		for (int i = 0; i < 5; i++)
		{
			if (temp[i] != 0)
			{
				board[r][pos] = temp[i];
				pos++;
			}
		}
	}
}

void move_right(int board[][5], int numrows = 5)
{
	//CODE HERE
}

void move_up(int board[][5], int numrows = 5)
{
	//CODE HERE
}

void move_down(int board[][5], int numrows = 5)
{
	//CODE HERE
}


void print_board(int board[][5], int numrows = 5)
{
	cout << endl << "\t-----------------------------------------" << endl;

	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if(board[r][c] > 0)
				cout << "\t|" << right << setw(6) << setfill(' ') << board[r][c];
			else
				cout << "\t|" << right << setw(6) << setfill(' ') << " ";

			//cout << board[r][c] << "\t|\t";
		}
		cout << "\t|" << endl;
		cout << "\t-----------------------------------------" << endl;
	}

	cout << "\t" << endl << endl;
}


void insert_random(int board[][5], int numrows = 5)
{
	int r, c;
	//count empty
	int empty_count = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				empty_count++;
		}
	}

	if (empty_count > 0)
	{
		while (true)
		{
			//generate random location r, c
			r = rand() % numrows;
			c = rand() % numrows;
			//check if empty
			if (board[r][c] == 0)
			{
				//add number randomly {2,4}
				board[r][c] = 2 * (1 + (rand() % 2));
				break;
			}
		}

	}
}

