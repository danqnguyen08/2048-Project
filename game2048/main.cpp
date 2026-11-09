#include <iostream>
#include "2048_helper.h"
using namespace std;

void print_help()
{
	cout << "Controls:" << endl;
	cout << "  u = move up    d = move down    l = move left    r = move right" << endl;
	cout << "  n = new game (asks you to confirm)" << endl;
	cout << "  h = show this help" << endl;
	cout << "  e = exit" << endl;
}

int main()
{
	int size = 5;
	int board[5][5];
	int score = 0;
	int moves = 0;

	new_game(board, size);

	cout << "Initial Board : [5x5] :" << endl;
	print_status(board, size, score, moves);
	print_help();

	char choice = 'u';	//initialized
	while (choice != 'e')
	{
		cout << "Please enter choice (u,d,l,r,n,h,e): ";
		if (!(cin >> choice))
			break;	// end of input

		if (choice == 'e')
		{
			cout << "Goodbye." << endl;
		}
		else if (choice == 'h')
		{
			print_help();
		}
		else if (choice == 'n')
		{
			char answer = 'n';
			cout << "Start a new game? Your current game will be lost (y/n): ";
			if (!(cin >> answer))
				break;	// end of input
			if (answer == 'y')
			{
				new_game(board, size);
				score = 0;
				moves = 0;
				cout << "New game started." << endl;
				print_status(board, size, score, moves);
			}
			else
			{
				cout << "New game cancelled." << endl;
			}
		}
		else if (choice == 'u' || choice == 'd' || choice == 'l' || choice == 'r')
		{
			int before[5][5];
			copy_board(board, before, size);

			if (choice == 'u')
				score += move_up(board, size);
			else if (choice == 'd')
				score += move_down(board, size);
			else if (choice == 'l')
				score += move_left(board, size);
			else
				score += move_right(board, size);

			// only a move that changed the board counts and adds a tile
			if (!boards_equal(before, board, size))
			{
				insert_random(board, size);
				moves++;
			}
			print_status(board, size, score, moves);
		}
		else
		{
			cout << "Invalid choice. Enter one letter (h for help)." << endl;
		}
	}

	return 0;
}