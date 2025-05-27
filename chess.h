#ifndef CHESS_H
#define CHESS_H


#define RANKS 8
#define FILES 8

#define BLACK ' '
#define WHITE ' '


#define BACKGROUND_PAIR1 1
#define BACKGROUND_PAIR2 2
#define HIGHLIGHT_PAIR 3


typedef struct {
	int select;
	char color;
	char type;
	int posy;
	int posx;

} Piece;

typedef struct {
	int select;
	char empty;
	int posy;
	int posx;
	Piece* piece;
} Tile;

typedef struct {
	Tile tiles[RANKS][FILES];
} Board;


Board* initboard();
void drawboard(Board* board);

Piece* initpiece(Board* board, char color, char type, int posx, int posy);

void highlightpiece(Board* board, Piece* piece);
void highlightpawn(Board* board, Piece* piece);
void movepiece(Board* board, int selectedy, int selectedx, int targety, int targetx);

void freeboard(Board* board);

#endif
