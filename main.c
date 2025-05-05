#include <stdio.h>
#include <stdlib.h>
#include "chess.h"


int main(int argc, char** argv){

	Board* board = initboard();


	drawboard(board);


	Piece* piece = initpiece('w', 'p', 1, 2);

	drawpiece(piece, board);
	


	free(board);
	free(piece);

	return 0;
}
