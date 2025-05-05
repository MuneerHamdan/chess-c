#ifndef TEST_H
#define TEST_H


#define RANKS 8
#define FILES 8


typedef struct {
	char type;
	char color;
	int pos[2];

} Piece;

typedef struct {
	int empty;
	int pos[2];
	Piece* piece;
} Tile;

typedef struct {
	Tile tiles[RANKS][FILES];
} Board;


void initboard(Board* board);
void drawboard(Board* board);


void initpiece(Piece* piece, char type, char color, int posx, int posy);
void drawpiece();

#endif
