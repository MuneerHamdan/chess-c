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


	Piece* wr1 = initpiece(board, 'w', 'r', 7, 0);
	Piece* wr2 = initpiece(board, 'w', 'r', 7, 7);

	Piece* br1 = initpiece(board, 'b', 'r', 0, 0);
	Piece* br2 = initpiece(board, 'b', 'r', 0, 7);


	Piece* wb1 = initpiece(board, 'w', 'b', 7, 1);
	Piece* wb2 = initpiece(board, 'w', 'b', 7, 6);

	Piece* bb1 = initpiece(board, 'b', 'b', 0, 1);
	Piece* bb2 = initpiece(board, 'b', 'b', 0, 6);


	Piece* wn1 = initpiece(board, 'w', 'n', 7, 2);
	Piece* wn2 = initpiece(board, 'w', 'n', 7, 5);

	Piece* bn1 = initpiece(board, 'b', 'n', 0, 2);
	Piece* bn2 = initpiece(board, 'b', 'n', 0, 5);

	Piece* wK = initpiece(board, 'w', 'K', 7, 3);
	Piece* wQ = initpiece(board, 'w', 'Q', 7, 4);

	Piece* bK = initpiece(board, 'b', 'K', 0, 3);
	Piece* bQ = initpiece(board, 'b', 'Q', 0, 4);

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

	int ch, x, y;
	ch = x = y = 0;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
//	getmaxyx(stdscr, y, x);

	printw("welcome to chess! press ESC to quit, any other to continue...");

	while ((ch = getch()) != 27) {

		clear();

		for (int i = 0; i < RANKS; i++) {
			for (int j = 0; j < FILES; j++) {

				if (board->tiles[i][j].piece != NULL) {
					printw("%c%c ", board->tiles[i][j].piece->type, board->tiles[i][j].piece->color);
				}
				else {
					printw("%c%c ", board->tiles[i][j].empty, board->tiles[i][j].empty);
				}

			}
			printw("\n");

		}

		printw("%d, %d", y, x);


		switch (ch) {
			case KEY_UP:
				y--;
				break;
			case KEY_DOWN:
				y++;
				break;
			case KEY_LEFT:
				x--;
				break;
			case KEY_RIGHT:
				x++;
				break;
			default:
				break;
		}

		move(y, x);

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
