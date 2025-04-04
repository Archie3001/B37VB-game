#ifndef UTT_READ_BOARD_H
#define UTT_READ_BOARD_H

#include "read_tile.h"
#include "../structs/board.h"

#include "../display/stats.h"

Board readBoard(FILE *save_file) {
	Board board;

	board.name = readString(save_file);

	board.x = readInt(save_file);
	board.y = readInt(save_file);

	board.grid = (Tile**)malloc(sizeof(Tile*)*board.x);
	for (int ix=0;ix<board.x;ix++) {
		board.grid[ix] = (Tile*)malloc(sizeof(Tile)*board.y);
		for (int iy=0;iy<board.y;iy++) {
//			board.grid[ix][iy] = //(Tile)malloc(sizeof(Tile));
			board.grid[ix][iy] = readTile(save_file);

			if (board.grid[ix][iy].being != NULL) {
//				Stats_print(board.grid[ix][iy].being->stats);
				Stats *temp = board.grid[ix][iy].being->stats;
				printf("Stats: \nSTR:%d\nHST:%d\nWIT:%d\nHP:%d\nSP:%d\nMP:%d\n",temp->str,temp->hst,temp->wit,temp->hp,temp->sp,temp->mp);
//				printf("test: %d\n",board.grid[ix][iy].being->stats->hst);
//				Stats_print()
			}
		}
	}
	return board;
}


#endif
