#ifndef HELPER_2048_H
#define HELPER_2048_H

int move_left(int board[][5], int numrows = 5);
int move_right(int board[][5], int numrows = 5);
int move_up(int board[][5], int numrows = 5);
int move_down(int board[][5], int numrows = 5);

void print_board(int board[][5], int numrows = 5);
void insert_random(int board[][5], int numrows = 5);
void copy_board(int from[][5], int to[][5], int numrows = 5);
bool boards_equal(int a[][5], int b[][5], int numrows = 5);
int highest_tile(int board[][5], int numrows = 5);
void new_game(int board[][5], int numrows = 5);
void print_status(int board[][5], int numrows, int score, int moves);
bool is_game_over(int board[][5], int numrows = 5);

bool save_game(const int board[][5], int score, int moves);
bool load_game(int board[][5], int& score, int& moves);

#endif