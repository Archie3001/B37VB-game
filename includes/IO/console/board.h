#ifndef UTT_PRINT_BOARD_H
#define UTT_PRINT_BOARD_H

#include <stdio.h>

int Board_print(const Board board){
	printf("Size: %dx%d\n",board.x,board.y);
	printf("%s:\n",board.name);


	//for each tile in board

	//print upper border
	printf("+-");
	for (int i=0;i<board.y;i++) {printf("--");}
	printf("+\n");

	for (int i=0;i<board.x;i++){
		printf("|");
		for (int j=0;j<board.y;j++){
			//if the tile doesn't have a being
			if (!board.grid[i][j].being) {
			//print a space
			printf("  ");

			//if the tile does have a being
			} else {
			//print the being's display character
			printf(" %c",board.grid[i][j].being->display_char);
			}
		}
		//print a new line character for each row of tiles
		printf(" |\n");
	}


	//print lower border
	printf("+-");
	for (int i=0;i<board.y;i++) {printf("--");}
	printf("+\n");
	//bye

	return 0;
}

#endif
