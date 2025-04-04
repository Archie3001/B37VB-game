#ifndef UTT_BOARD_H
#define UTT_BOARD_H

#include "tile.h"
#include "player.h"

typedef struct { //Board
	char *name;
	int x;
	int y;
	Tile **grid;
	Player player;
} Board;

Board Board_new(char *name,int x,int y) {

//	static Being wall = {'#','#',"wall",(Stats*)NULL};

	Tile air_tile = {&AIR,0};

	//initialise with given parameters
	Board board = {name,x,y};
	board.player.being = (Being*)NULL;//malloc(sizeof(Being));

	//malloc it up in there
	board.grid = (Tile**)malloc(sizeof(Tile*)*x);

	//go through x dimension
	for (int ix=0;ix<x;ix++) {

		//malloc it up in there
		board.grid[ix] = (Tile*)malloc(sizeof(Tile)*y);

		//and the y dimension
		for (int iy=0;iy<y;iy++) {
			board.grid[ix][iy] = air_tile;
		}
	}

	/// *just seeing how pointers work exactly;
	//I now understand
	//delete the line below to execute this stuff
	/*
	printf("pointer: %p\n",board.grid);
	printf("pointer: %p\n",board.grid[0][0]);
	printf("pointer: %p\n",board.grid[1]);
	printf("pointer: %p\n",board.grid[2]);
	//*/

	return board;
}

void Board_freeParts(Board board) {
//	printf("Board: %s\n",board.name);
	for (int ix=0; ix<board.x; ix++) {
		for (int iy=0; iy<board.y; iy++) {
//			printf("Tile: %d, %d\n",ix,iy);
			Tile_freeParts(board.grid[ix][iy]);
		}
//		printf("test\n");
		free(board.grid[ix]);
	}
	free(board.grid);
}

#endif

