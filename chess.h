#ifndef CHESS_H
#define CHESS_H


#define RANKS 8
#define FILES 8

#define BLACK '_'
#define WHITE '#'


typedef struct {
	int select;
	char color;
	char type;
	int posy;
	int posx;

} Piece;

typedef struct {
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

//Piece* highlightpiece(Board* board, int selectedy, int selectedx);
void highlightpiece(Board* board, Piece* piece);
//void movepiece(Board* board, int selectedy, int selectedx);
void movepiece(Board* board, int selectedy, int selectedx, int targety, int targetx);
//void movepiece(Board* board, Piece* piece1, Piece* piece2);

void freeboard(Board* board);

#endif
