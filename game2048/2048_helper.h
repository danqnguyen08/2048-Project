#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
using namespace std;

int move_left(int board[][5], int numrows = 5)
{
	int gained = 0;
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
				gained += temp[i];
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
	return gained;
}

int move_right(int board[][5], int numrows = 5)
{
	int gained = 0;
	for (int r = 0; r < numrows; r++)
	{
		//Step 1: slide non-zero tiles to the right (read from the right end)
		int temp[5] = {0,0,0,0,0};
		int pos = 0;
		for (int c = 4; c >= 0; c--)
		{
			if (board[r][c] != 0)
			{
				temp[pos] = board[r][c];
				pos++;
			}
		}

		//Step 2: merge equal neighbors
		for (int i = 0; i < 4; i++)
		{
			if (temp[i] != 0 && temp[i] == temp[i + 1])
			{
				temp[i] = temp[i] * 2;
				gained += temp[i];
				temp[i + 1] = 0;
				i++;
			}
		}

		//Step 3: slide again, placing tiles from the right end of the row
		for (int c = 0; c < 5; c++)
		{
			board[r][c] = 0;
		}
		pos = 0;
		for (int i = 0; i < 5; i++)
		{
			if (temp[i] != 0)
			{
				board[r][4 - pos] = temp[i];
				pos++;
			}
		}

	}
	return gained;
}

int move_up(int board[][5], int numrows = 5)
{
	int gained = 0;
	for (int c = 0; c < 5; c++)
	{
		//Step 1: slide non-zero tiles toward the top
		int temp[5] = {0,0,0,0,0};
		int pos = 0;
		for (int r = 0; r < numrows; r++)
		{
			if (board[r][c] != 0)
			{
				temp[pos] = board[r][c];
				pos++;
			}
		}

		//Step 2: merge equal neighbors
		for (int i = 0; i < 4; i++)
		{
			if (temp[i] != 0 && temp[i] == temp[i + 1])
			{
				temp[i] = temp[i] * 2;
				gained += temp[i];
				temp[i + 1] = 0;
				i++;
			}
		}

		//Step 3: slide again, writing back from the top
		for (int r = 0; r < numrows; r++)
		{
			board[r][c] = 0;
		}
		pos = 0;
		for (int i = 0; i < 5; i++)
		{
			if (temp[i] != 0)
			{
				board[pos][c] = temp[i];
				pos++;
			}
		}
	}
	return gained;
}

int move_down(int board[][5], int numrows = 5)
{
	int gained = 0;
	for (int c = 0; c < 5; c++)
	{
		//Step 1; slide non-zero tiles toward the bottom (read from the bottom)
		int temp[5] = {0,0,0,0,0};
		int pos = 0;
		for (int r = numrows - 1; r >= 0; r--)
		{
			if (board[r][c] != 0)
			{
				temp[pos] = board[r][c];
				pos++;
			}
		}

		//Step 2: merge equal neighbors
		for (int i = 0; i < 4; i++)
		{
			if (temp[i] != 0 && temp[i] == temp[i + 1])
			{
				temp[i] = temp[i]*2;
				gained += temp[i];
				temp[i + 1] = 0;
				i++;
			}
		}

		//Step 3: slide again, writing back from the bottom 
		for (int r = 0; r < numrows; r++)
		{
			board[r][c] = 0;
		}
		pos = 0;
		for (int i = 0; i < 5; i++)
		{
			if (temp[i] != 0)
			{
				board[numrows - 1 - pos][c] = temp[i];
				pos++;
			}
		}
	}
	return gained;
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

void copy_board(int from[][5], int to[][5], int numrows = 5)
{
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			to[r][c] = from[r][c];
		}
	}
}

bool boards_equal(int a[][5], int b[][5], int numrows = 5)
{
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (a[r][c] != b[r][c])
				return false;
		}
	}
	return true;
}

int highest_tile(int board[][5], int numrows = 5)
{
	int highest = 0;
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] > highest)
				highest = board[r][c];
		}
	}
	return highest;
}

void new_game(int board[][5], int numrows = 5)
{
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			board[r][c] = 0;
		}
	}
	insert_random(board, numrows);
	insert_random(board, numrows);
}

void print_status(int board[][5], int numrows, int score, int moves)
{
	print_board(board, numrows);
	cout << "\tScore: " << score << "   Moves: " << moves
	     << "   Highest tile: " << highest_tile(board, numrows) << endl << endl;
}

bool is_game_over(int board[][5], int numrows = 5)
{
	for (int r = 0; r < numrows; r++)
	{
		for (int c = 0; c < 5; c++)
		{
			if (board[r][c] == 0)
				return false;	// an empty cell means a move is possible
			if (c < 4 && board[r][c] == board[r][c + 1])
				return false;	// equal neighbors side by side
			if (r < numrows - 1 && board[r][c] == board[r + 1][c])
				return false;	// equal neighbors one above the other
		}
	}
	return true;
	
}


 // Check if a tile is valid
bool valid_tile(int tile)
{
    if (tile == 0)
        return true;

    if (tile < 2)
        return false;

    while (tile > 1)
    {
        if (tile % 2 != 0)
            return false;

        tile = tile / 2;
    }

    return true;
}


// Save the current game
bool save_game(const int board[][5], int score, int moves)
{
    ofstream file("savegame.txt");

    if (!file.is_open())
        return false;

    file << "CS211_2048_V1" << endl;
    file << score << " " << moves << endl;

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (c > 0)
                file << " ";

            file << board[r][c];
        }

        file << endl;
    }

    file.close();

    if (file.fail())
        return false;

    return true;
}


bool load_game(int board[][5], int& score, int& moves)
{
    ifstream file("savegame.txt");

    if (!file.is_open())
        return false;

    char marker[32] = {};
    const char expected[] = "CS211_2048_V1";

    int saved_score;
    int saved_moves;
    int saved_board[5][5];

    if (!(file >> setw(32) >> marker))
        return false;

    int i = 0;

    while (expected[i] != '\0' &&
           marker[i] == expected[i])
    {
        i++;
    }

    if (expected[i] != '\0' || marker[i] != '\0')
        return false;

    if (!(file >> saved_score >> saved_moves))
        return false;

    if (saved_score < 0 || saved_moves < 0)
        return false;

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            if (!(file >> saved_board[r][c]))
                return false;

            if (!valid_tile(saved_board[r][c]))
                return false;
        }
    }

    char extra;

    if (file >> extra)
        return false;

    if (file.bad())
        return false;

    for (int r = 0; r < 5; r++)
    {
        for (int c = 0; c < 5; c++)
        {
            board[r][c] = saved_board[r][c];
        }
    }

    score = saved_score;
    moves = saved_moves;

    return true;
}
