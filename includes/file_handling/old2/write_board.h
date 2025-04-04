#ifndef UTT_WRITE_BOARD_H
#define UTT_WRITE_BOARD_H

#include "write_tile.h"
#include "parse_strings.h"
#include "parse_int.h"

void writeBoard(FILE *save_file,Board *board){
//	fputc((char)getStringLength(board->name),save_file);
//	fprintf("%s",board->name);

	writeString(save_file,board->name);

	saveInt(save_file,board->x);
	saveInt(save_file,board->y);

	for (int ix=0;ix<board->x;ix++) {
		for (int iy=0;iy<board->y;iy++) {
			writeTile(save_file,&board->grid[ix][iy]);
	}	}
}


#endif
