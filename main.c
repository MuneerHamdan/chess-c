#include <stdio.h>
#include <stdlib.h>
#include "chess.h"


int main(int argc, char** argv){

	Board* board = initboard();

	drawboard(board);

//	freeboard(board);

	return 0;
}
