#include "chess.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>



//FUNCTION DEFINITIONS


Board* initboard() {
	Board* board = malloc(sizeof(Tile[RANKS][FILES]));
	for (int i = 0; i < RANKS; i++) {
		for (int j = 0; j < FILES; j++) {
			board->tiles[i][j].pos[0] = i;
			board->tiles[i][j].pos[1] = j;
			if ((i + j) % 2 == 0)
				board->tiles[i][j].empty = BLACK;
			else
				board->tiles[i][j].empty = WHITE;
			board->tiles[i][j].piece = NULL;
		}
	}

	Piece* wp0 = initpiece(board, 'w', 'p', 6, 0);
	Piece* wp1 = initpiece(board, 'w', 'p', 6, 1);
	Piece* wp2 = initpiece(board, 'w', 'p', 6, 2);
	Piece* wp3 = initpiece(board, 'w', 'p', 6, 3);
	Piece* wp4 = initpiece(board, 'w', 'p', 6, 4);
	Piece* wp5 = initpiece(board, 'w', 'p', 6, 5);
	Piece* wp6 = initpiece(board, 'w', 'p', 6, 6);
	Piece* wp7 = initpiece(board, 'w', 'p', 6, 7);


	Piece* bp0 = initpiece(board, 'b', 'p', 1, 0);
	Piece* bp1 = initpiece(board, 'b', 'p', 1, 1);
	Piece* bp2 = initpiece(board, 'b', 'p', 1, 2);
	Piece* bp3 = initpiece(board, 'b', 'p', 1, 3);
	Piece* bp4 = initpiece(board, 'b', 'p', 1, 4);
	Piece* bp5 = initpiece(board, 'b', 'p', 1, 5);
	Piece* bp6 = initpiece(board, 'b', 'p', 1, 6);
	Piece* bp7 = initpiece(board, 'b', 'p', 1, 7);
	

	return board;
}

Piece* initpiece(Board* board, char type, char color, int posx, int posy) {
	Piece* piece = malloc(sizeof(Piece));

	piece->type = type;
	piece->color = color;
	piece->pos[0] = posx;
	piece->pos[1] = posy;

	board->tiles[posx][posy].piece = piece;

	return piece;
}


void drawboard(Board* board) {

	int ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	printw("welcome to chess! press ESC to quit, any other to continue...");

	while ((ch = getch()) != 27) {

		clear();

		for (int i = 0; i < RANKS; i++) {
			for (int j = 0; j < FILES; j++) {

				if (board->tiles[i][j].piece != NULL) {
					printw("%c%c ", board->tiles[i][j].piece->type, board->tiles[i][j].piece->color);
				}
				else {
					printw(" %c ", board->tiles[i][j].empty);
				}

			}
		printw("\n");

	}


		refresh();

	}

	refresh();
	endwin();

	freeboard(board);
}


void freeboard(Board* board) {
	for (int i = 0; i < RANKS; ++i) {
		for (int j = 0; j < FILES; ++j) {
			if (board->tiles[i][j].piece != NULL)
				free(board->tiles[i][j].piece);
		}
	}

	free(board);
}
