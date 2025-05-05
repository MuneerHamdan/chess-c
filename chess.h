#ifndef TEST_H
#define TEST_H


#define RANKS 8
#define FILES 8

#define BLACK '_'
#define WHITE '#'


typedef struct {
	char color;
	char type;
	int pos[2];

} Piece;

typedef struct {
	char empty;
	int pos[2];
	Piece* piece;
} Tile;

typedef struct {
	Tile tiles[RANKS][FILES];
} Board;


Board* initboard();
void drawboard(Board* board);

Piece* initpiece(Board* board, char color, char type, int posx, int posy);

void freeboard(Board* board);

#endif
