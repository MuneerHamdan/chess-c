#include "test2.h"
#include <stdio.h>



//FUNCTION DEFINITIONS

void initboard(Board* b) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			b->tiles[i][j].pos[0] = i;
			b->tiles[i][j].pos[1] = j;
			b->tiles[i][j].empty = 0;
			b->tiles[i][j].piece = NULL;
		}
	}

	
}


void drawboard(Board* board) {
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){

//			printf("(%d, %d) ", board->tiles[i][j].pos[0], board->tiles[i][j].pos[1]);
			printf("(%d) ", board->tiles[i][j].empty);
		}
		printf("\n");
	}
}


void initpiece(Piece* piece, char type, char color, int posx, int posy) {
	piece->type = type;
	piece->color = color;
	piece->pos[0] = posx;
	piece->pos[1] = posy;
}
