#include <iostream>
#include "2048_helper.h"
using namespace std;

int main()
{
	int size = 5;
	int board[5][5];
	int score = 0;
	int moves = 0;

	new_game(board, size);

	cout << "Initial Board : [5x5] :" << endl;
	print_status(board, size, score, moves);

	char choice = 'u';	//initialized
	while (choice != 'e')
	{
		cout << "Please enter choice:{u,d,l,r,e} for UP, DOWN, LEFT, RIGHT, Exit: " << endl;
		cout << "Choice: ";
		if (!(cin >> choice))
			break;	// end of input

		if (choice == 'e')
			break;

		int before[5][5];
		copy_board(board, before, size);

		bool is_move = true;
		if (choice == 'u')
			score += move_up(board, size);
		else if (choice == 'd')
			score += move_down(board, size);
		else if (choice == 'l')
			score += move_left(board, size);
		else if (choice == 'r')
			score += move_right(board, size);
		else
			is_move = false;

		if (!is_move)
		{
			cout << "Invalid choice." << endl;
			continue;
		}

		// only a move that changed the board counts and adds a tile
		if (!boards_equal(before, board, size))
		{
			insert_random(board, size);
			moves++;
		}
		print_status(board, size, score, moves);
	}

	return 0;
}