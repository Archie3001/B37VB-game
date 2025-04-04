#ifndef UTT_BOARD_H
#define UTT_BOARD_H

#include "tile.h"

typedef struct {
	int x;
	int y;
	Tile **grid;
} Board;

Board Board_build(int x,int y) {
	//init
	Board board = {x,y};
	Tile **grid;
	grid = (Tile**)malloc(sizeof(Tile)*x*y);
	for (int i=0;i<x;i++) {
		grid[i] = malloc(sizeof(Tile)*y);
		for (int j=0;j<y;j++) {
//			grid[i][j] = (Tile)malloc(sizeof(Tile));
			grid[i][j] = blank_tile;
			printf("%c",grid[i][j].display_char);
		}
	}
	printf("\n");
	board.grid = grid;
	return board;
}

Board Board_load(save_file_name) {
        FILE *save_file;
        save_file = fopen(save_file_name,"r");

        if (save_file == NULL) {
                return NULL
        };

}

#endif
