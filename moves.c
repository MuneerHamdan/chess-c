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


	switch (piece1->type) {
		case 'p':
			//highlightpiece(board, board->tiles[][+2];

			break;
		case 'r':
			break;
		case 'b':
			break;
		case 'n':
			break;
		case 'q':
			break;
		case 'k':
			break;
		default:
			break;
			}

	// if piece1 == w piece2 has to be b so on
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
