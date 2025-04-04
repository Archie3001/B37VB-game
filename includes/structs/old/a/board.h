#ifndef UTT_BOARD
#define UTT_BOARD

#include "tile.h"

//what is the board structure going to be
//it needs to contain a 15x15 grid of tiles
//it does not need more than that

struct Board
{
	int x,y;
	struct Tile ***grid;
};

struct Board Board_build(int x,int y) {
// in a function of course
//test **t = (test **)malloc(20 * sizeof(test *));
//for (i = 0; i < 20; ++i)
//    t[i] = (test *)malloc(20 * sizeof(test));

//	struct Tile **grid = (struct Tile **)malloc(x*sizeof(struct Tile *));
//	for (i=0;i<x;i++) {
//		grid[i] = (struct Tile *)malloc(y*sizeof(struct Tile));
//		for (j=0;j<y;j++) {
//			grid[i][j] = BLANK_TILE;
//		}
//	}

//	struct Tile grid[x][y];
//	for (int i=0;i<x;i++){for (int j=0;i<y;j++){grid[i][j] = BLANK_TILE;}}

	struct Tile ***grid;

	grid = (struct Tile***)malloc(sizeof(struct Tile *)*x*y);

	for (int i=0;i<x;i++)
		{
		for (int j=0;i<y;j++){
		grid[i][j] = malloc(sizeof(struct Tile));
		grid[i][j]->being = malloc(sizeof(struct Being));
		}
	}

	struct Board board = {x,y,grid};
	return board;
};

#endif
