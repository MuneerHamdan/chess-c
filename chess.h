#ifndef TEST_H
#define TEST_H


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

void highlightpiece(Board* board, int selectedy, int selectedx);
void movepiece(Board* board, int selectedy, int selectedx, int targety, int targetx);

void freeboard(Board* board);

#endif
