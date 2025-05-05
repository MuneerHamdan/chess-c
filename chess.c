#include "chess.h"
#include <stdio.h>
#include <ncurses.h>



//FUNCTION DEFINITIONS


void initboard(Board* b) {
	for (int i = 0; i < RANKS; i++) {
		for (int j = 0; j < FILES; j++) {
			b->tiles[i][j].pos[0] = i;
			b->tiles[i][j].pos[1] = j;
			b->tiles[i][j].empty = 0;
			b->tiles[i][j].piece = NULL;
		}
	}


}


void drawboard(Board* board) {

	int ch;

	initscr();
	//	raw();
	//	keypad(stdscr, TRUE);
	noecho();

	printw("welcome to chess");
	clear();
	for (int i = 0; i < RANKS; i++) {
		for (int j = 0; j < FILES; j++) {

			printw("(%d) ", board->tiles[i][j].empty);
		}
		printw("\n");
	}

	while ((ch = getch()) != 27){
		refresh();

	}

	refresh();
	endwin();
}


void initpiece(Piece* piece, char type, char color, int posx, int posy) {
	piece->type = type;
	piece->color = color;
	piece->pos[0] = posx;
	piece->pos[1] = posy;
}
