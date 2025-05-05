#include "chess.h"
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>


Board* initboard() {
	Board* board = malloc(sizeof(Tile[RANKS][FILES]));
	for (int i = 0; i < RANKS; i++) {
		for (int j = 0; j < FILES; j++) {
			board->tiles[i][j].posy = i;
			board->tiles[i][j].posx = j;
			board->tiles[i][j].piece = NULL;
			if ((i + j) % 2 == 0)
				board->tiles[i][j].empty = BLACK;
			else
				board->tiles[i][j].empty = WHITE;
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

Piece* initpiece(Board* board, char type, char color, int posy, int posx) {
	Piece* piece = malloc(sizeof(Piece));

	piece->select = -1;
	piece->type = type;
	piece->color = color;
	piece->posy = posy;
	piece->posx = posx;

	board->tiles[posy][posx].piece = piece;

	return piece;
}


void drawboard(Board* board) {

	int ch, x, y;
	ch = x = y = 0;
	int selected[2];
	selected[0] = selected[1] = -1;
	int targeted[2];
	targeted[0] = targeted[1] = -1;

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
					if (board->tiles[i][j].piece->select == 1) {
						addch(board->tiles[i][j].piece->type | A_BLINK);
						addch(board->tiles[i][j].piece->color | A_BLINK);
						printw(" ");
					}
					else
						printw("%c%c ", board->tiles[i][j].piece->type, board->tiles[i][j].piece->color);
//						printw("(%d, %d) ", board->tiles[i][j].piece->posy, board->tiles[i][j].piece->posx);
				}
				else {
					printw("%c%c ", board->tiles[i][j].empty, board->tiles[i][j].empty);
				}

			}
			printw("\n");

		}



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
			case 106:
				y++;
				break;
			case 107:
				y--;
				break;
			case 104:
				x = x - 3;
				break;
			case 108:
				x = x + 3;
				break;
			case 10:
				if ((selected[0] == -1 || selected[1] == -1) && (board->tiles[y][x / 3].piece != NULL)) {
					selected[0] = x / 3;
					selected[1] = y;
					highlightpiece(board, selected[0], selected[1]);
				}
				else {
					targeted[0] = x / 3;
					targeted[1] = y;
					movepiece(board, selected[0], selected[1], targeted[0], targeted[1]);
					selected[0] = -1;
					selected[1] = -1;

				}
			default:
				//				printw("character pressed is = %3d. will get printed as '%c'\n", ch, ch);
				//				printw("y: %3d, x: %3d\n", x, y);
				//				printw("targety: %d, x: %d", targeted[0], targeted[1]);
				break;
		}

		printw("%d, %d\n", y, x);
		printw("boardy: %d, x: %d\n", y, x);
		printw("selectedy: %d, x: %d\n", selected[0], selected[1]);
		printw("targety: %d, x: %d\n", targeted[0], targeted[1]);
		printw("piece ptr: %p\n", board->tiles[y][x / 3].piece);
		move(y, x);


		refresh();

	}

	refresh();
	endwin();

	freeboard(board);
}


void highlightpiece(Board* board, int selectedy, int selectedx){
	if (board->tiles[selectedx][selectedy].piece != NULL)
		board->tiles[selectedx][selectedy].piece->select = 1;
}

void movepiece(Board* board, int selectedy, int selectedx, int targety, int targetx) {
	if (board->tiles[targety][targetx].piece == NULL){
		board->tiles[selectedy][selectedx].piece->posy = board->tiles[targety][targetx].piece->posy;
		board->tiles[selectedy][selectedx].piece->posx = board->tiles[targety][targetx].piece->posx;
	}
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
