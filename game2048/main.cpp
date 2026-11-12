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
	cout << "  s = save game" << endl;
	cout << "  o = open saved game" << endl;
	cout << "  Saving replaces the previous savegame.txt." << endl;
}

int main()
{
	int size = 5;
	int board[5][5];
	int score = 0;
	int moves = 0;
	bool won = false;

	new_game(board, size);

	cout << "Initial Board : [5x5] :" << endl;
	print_status(board, size, score, moves);
	print_help();

	char choice = 'u';	//initialized
	while (choice != 'e')
	{
		cout << "Please enter choice (u,d,l,r,s,o,n,h,e): ";
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
		else if (choice == 's')
		{
   			 if (save_game(board, score, moves))
       		 cout << "Game saved successfully." << endl;
   		 else
       		 cout << "Error saving game." << endl;
		}
		else if (choice == 'o')
		{
   			if (load_game(board, score, moves))
    		{
       			won = (highest_tile(board, size) >= 2048);

      			cout << "Game loaded successfully." << endl;
        print_status(board, size, score, moves);
    }
    else
    {
        cout << "Error loading game." << endl;
    }
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
				won = false;
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
			if (is_game_over(board, size))
			{	
				cout << "Game over! Use s to save, o to load, n for a new game, h for help, or e to exit." << endl;
			}	
			else
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

				if (!won && highest_tile(board, size) >= 2048)
				{
					cout << "You reached 2048! You can keep playing." << endl;
					won = true;
				}
				if (is_game_over(board, size))	
				{	
					cout << "Game over! No empty cells and no equal neighbors." << endl;
				}	
			}	
		}
		else
		{
			cout << "Invalid choice. Enter one letter (h for help)." << endl;
		}
	}

	return 0;
}