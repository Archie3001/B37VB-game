#ifndef UTT_PLAYER_MOVE_H
#define UTT_PLAYER_MOVE_H

#include "board.h"

char Player_move(int dx,int dy,Board *board) {
	printf("Player ptr: %p\n",board->player.being);

	if (board->player.being == (Being*)NULL) {// || !(board.player.being == board.grid[board.player.x][board.player.y].being)) {
		printf("Player ptr: %p\n",board->player.being);
		if (!Board_findPlayer(board)) {
			printf("player not found (%p)",board->player.being);
			return 100;//player not found
		}
	}
	switch (Board_checkStance(*board,board->player.x+dx,board->player.y+dy)) {
		case ' ':
			printf("empty space\n");
			board->grid[board->player.x+dx][board->player.y+dy].being = board->grid[board->player.x][board->player.y].being;
			board->grid[board->player.x][board->player.y].being = &AIR;
			board->player.x += dx;
			board->player.y += dy;
			return ' ';//free to move
		case '/':
			printf("door\n");
			board->grid[board->player.x+dx][board->player.y+dy].being = board->grid[board->player.x][board->player.y].being;
			board->grid[board->player.x][board->player.y].being = &AIR;
			board->player.x += dx;
			board->player.y += dy;
			return ' ';//free to move
		case '^':
			printf("stairs up\n");
			return '^';
		case 'v':
			printf("stairs down\n");
			return 'v';
		case 'E':
			printf("enemy\n");
			return 'E';
		case '#':
			printf("wall\n");
			return '#';
		case '\0':
			printf("out of bounds\n");
			return '\0';
		default:
			char temp = Board_checkStance(*board,board->player.x+dx,board->player.y+dy);
			printf("undefined: '%c'(%d)\n",temp,temp);
//		default:
//			printf("case: '%c', %d\n",temp,temp);
	}
}





#endif
