#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "chess.h"


void movepiece(Board* board, int sy, int sx, int ty, int tx) {
	
//	sy = piece1->posy;
//	sx = piece1->posx;

	Piece* tmp = NULL;

	Piece* piece1 = board->tiles[sy][sx].piece;
	Piece* piece2 = board->tiles[ty][tx].piece;

	if (piece2 != NULL) {
	}
	else if (piece2 == NULL) {
		//printw("here\n");
		board->tiles[ty][tx].piece = piece1;
		board->tiles[sy][sx].piece = NULL;
		piece1->posy = ty;
		piece1->posx = tx;
	}
}
