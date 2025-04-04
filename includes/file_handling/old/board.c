#ifndef UTT_FILE_BOARD_C
#define UTT_FILE_BOARD_C

#include "../struct/board.c"

Board Board_load(FILE *save_file, Board board) {
	if (save_file == NULL) {
		return NULL;
	}

	//two ints, x & y
	char save[8] = {
		(char) (board.x)
		(char) (board.x >> 8)
		(char) (board.x >>16)
		(char) (board.x >>24)
		(char) (board.y)
		(char) (board.y >> 8)
		(char) (board.y >>16)
		(char) (board.y >>24)
	};

	for (int ix=0;ix<board.x;ix++) {
		for (int iy=0;iy<board.y;iy++) {
			if (board[ix][iy].thing == )
	}	}

}

#endif
