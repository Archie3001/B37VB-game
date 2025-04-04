#ifndef UTT_PLAYER_BOARD_H
#define UTT_PLAYER_BOARD_H

int *Board_findBeingOfStance(Board *board,char stance) {
	static int being_pos[2] = {-1,-1};
	for (int ix=0;ix<board->x;ix++) {
		for (int iy=0;iy<board->y;iy++) {
			if (board->grid[ix][iy].being->stance == stance) {
				being_pos[0] = ix;
				being_pos[1] = iy;
				return being_pos;
			}
		}
	}
	return being_pos;
}

int Board_findPlayer(Board *board) {
//	Board board = *board_ptr;
	for (int ix=0;ix<board->x;ix++) {
		for (int iy=0;iy<board->y;iy++) {
			if (board->grid[ix][iy].being->stance == 'P') {
				printf("player found\n");
//				printf("(x,y): (%d,%d)\n",board->player.x,board.player.y);
				board->player.x = ix;
				board->player.y = iy;
				board->player.being = board->grid[ix][iy].being;
				printf("player: ");
				printf("ptr: %p ",board->player.being);
				printf("(x,y): (%d,%d)\n",board->player.x,board->player.y);
				return 1;
			}
		}
	}
	printf("player not found\n");
	return 0;
}


void Board_tick(Board board,int ticks) {
	return;
}

int Board_checkBounds(Board board,int x,int y) {
	if ( x < 0 || y < 0 || x >= board.x || y >= board.y ) {
		return 1;//out of bounds
	} else {
		return 0;//within bounds
	}
}

char Board_checkStance(Board board,int x,int y) {
	if (Board_checkBounds(board,x,y)) {
		return '\0';//out of bounds
	} else if (board.grid[x][y].being == (Being*)NULL) {
		return ' ';//no being == air
	} else {
		return board.grid[x][y].being->stance;
	}
}


#endif
