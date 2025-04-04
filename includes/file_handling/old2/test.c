#include <stdio.h>
#include <stdlib.h>
#include "read_tower.h"
#include "write_tower.h"

int main () {
	Being temp;
	Stats *stats;
	Tile tile_test;

	FILE *same_save_file = fopen("test.bin","w");
//	fprintf(same_save_file,"%c%c%c%s%c%s%c",'A','B',5,"hello",3,"gif",'F');

	Stats save_stats  = {1,2,3,4,5,6};

	Being being_to_save = {
		'A',
		'B',
		"hello",
		"gif",
		&save_stats
	};

	Tile tile_to_save = {
		&being_to_save
	};

	Tile empty_tile = {
		(Being*)NULL
	};

	Board board_to_save = newBoard("floor",3,2);

/*{
		"floor",
		3,
		2
	};

	/*
		empty_tile,
		empty_tile,
		empty_tile,
		empty_tile,
		empty_tile,
		empty_tile
	};*/

	board_to_save.grid[0][1] = tile_to_save;

	writeBoard (same_save_file,  &board_to_save);

	fclose(same_save_file);

	FILE *save_file = fopen("test.bin","r");
	//if (testExists(save_file)) {
	//	printf("being exists\n");
	//} else {
	//	printf("being dont exist\n");
	//}
	Board board = readBoard(save_file);
	tile_test = board.grid[0][1];
	temp = *tile_test.being;
	Being being = temp;
	//stats = &temp;
	fclose(save_file);
	printf("%c%c\"%s\",\"%s\"%p\n",being.display_char,being.stance,being.name,being.image_name,being.stats);

	if (being.stats != (Stats*)NULL) {
		stats = being.stats;
		printf("stats: %d,%d,%d,%d,%d,%d\n",stats->str,stats->hst,stats->wit,stats->hp,stats->sp,stats->mp);
	}

//	printf("board:\n%p,%p,%p\n%p,%p,%p\n",board.grid[0][0],board.grid[1][0],board.grid[2][0],board.grid[0][1],board.grid[1][1],board.grid[1][2]);

	return 0;
}
