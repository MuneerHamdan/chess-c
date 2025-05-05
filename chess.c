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

	return board;
}


void drawboard(Board* board) {

	Piece* wp0 = initpiece('w', 'p', 6, 0);
	Piece* wp1 = initpiece('w', 'p', 6, 1);
	Piece* wp2 = initpiece('w', 'p', 6, 2);
	Piece* wp3 = initpiece('w', 'p', 6, 3);
	Piece* wp4 = initpiece('w', 'p', 6, 4);
	Piece* wp5 = initpiece('w', 'p', 6, 5);
	Piece* wp6 = initpiece('w', 'p', 6, 6);
	Piece* wp7 = initpiece('w', 'p', 6, 7);




	int ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	printw("welcome to chess! press ESC to quit, any other to continue...");

	while ((ch = getch()) != 27){
		clear();

		drawpiece(wp0, board);
		drawpiece(wp1, board);
		drawpiece(wp2, board);
		drawpiece(wp3, board);
		drawpiece(wp4, board);
		drawpiece(wp5, board);
		drawpiece(wp6, board);
		drawpiece(wp7, board);

		for (int i = 0; i < RANKS; i++) {
			for (int j = 0; j < FILES; j++) {

				printw("%c", board->tiles[i][j].empty);
		//		printw("%c", board->tiles[i][j].piece->type);
			}
		printw("\n");

	}


		refresh();

	}

	refresh();
	endwin();
	free(wp0);
	free(wp1);
	free(wp2);
	free(wp3);
	free(wp4);
	free(wp5);
	free(wp6);
	free(wp7);
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
	char type = piece->type;
	board->tiles[x][y].empty = type;
}
