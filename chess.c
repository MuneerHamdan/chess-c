#include "chess.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>



//FUNCTION DEFINITIONS


Board* initboard() {
	Board* board = malloc(sizeof(Board));
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

	return board;
}


void drawboard(Board* board) {

	int ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	printw("welcome to chess! press ESC to quit, any other to continue...");

	while ((ch = getch()) != 27){
		clear();

		for (int i = 0; i < RANKS; i++) {
			for (int j = 0; j < FILES; j++) {

				printw("%c", board->tiles[i][j].empty);
				printw("%c", board->tiles[i][j].piece->type);
			}
		printw("\n");

	}

		if (ch == KEY_LEFT)
			board->tiles[4][3].empty = 1;
		else
			board->tiles[4][3].empty = 3;

		refresh();

	}

	refresh();
	endwin();
}


Piece* initpiece(char type, char color, int posx, int posy) {
	Piece* piece = malloc(sizeof(Piece));
	piece->type = type;
	piece->color = color;
	piece->pos[0] = posx;
	piece->pos[1] = posy;

	return piece;
}


void drawpiece(Piece* piece, Board* board) {
	int x = piece->pos[0];
	int y = piece->pos[1];
	printf("%d", x);
	char type = piece->type;
	board->tiles[x][y].empty = type;
	printf("%c", board->tiles[1][2].empty);
}
