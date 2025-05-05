all:
	gcc chess.c main.c -o chess -lncurses
	./chess
