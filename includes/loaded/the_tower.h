#include "../IO/console/item.h"
#include "../IO/console/being.h"
#include "../.structs.h"
#include "board.h"
#include "beings.h"
#include "floors.h"

Tower *makeTheTower() {
	//this is a non-filesystem save of the tower
	//for testing mostly

	Item *items = define_items();
	Being *beings = define_beings(items);
	Being_print (beings[0]);

//	for (int i=0;i<3;i++) {
//		Item_print(items[i]);
//	}


//	Stats player_stats = {10,10,10,10,10,10};
	Being *player = Being_new('P','P',"you");
	Stats_set(&player->stats,10,10,10,10,10,10);
//	player->stats = (Stats*)malloc(sizeof(Stats));
//	player->stats = &player_stats;

	printf("player stance: %c\n",player->stance);

	printf("makeTheTower called\n");

	Tower *tower = Tower_new("West Hill Tower",5);

	printf("makeTheTower checkpoint 1\n");

//	Board first_floor = Board_new("first floor",15,15);

//	tower->floors[0] = first_floor;

	tower->floors[0] = Board_new("first Floor",15,15);
	Board_gridTextRead(&tower->floors[0],FLOOR_1_STRING);

	tower->floors[1] = Board_new("Second Floor",15,15);
	Board_gridTextRead(&tower->floors[1],FLOOR_2_STRING);

	tower->floors[2] = Board_new("Third Floor",15,15);
	Board_gridTextRead(&tower->floors[2],FLOOR_3_STRING);

	tower->floors[3] = Board_new("Fourth Floor",15,15);
	Board_gridTextRead(&tower->floors[3],FLOOR_4_STRING);

	tower->floors[4] = Board_new("Fifth Floor",15,15);
	Board_gridTextRead(&tower->floors[4],FLOOR_5_STRING);

//	relic of testing:
//	char * floor_1_char = "################             ##     ##########      ###    #######  ##    ###       #    ### ###  #### ###    ####     ##             ##    ####     ############# #####   ####    ##             ##     # ##    ######## #######";

	printf("makeTheTower checkpoint 2\n");

//	Board_gridTextRead(&first_floor,floor_1_char);

//	Board_readGridFile(&first_floor,"./includes/loaded/floors.txt");

	tower->floors[0].grid[14][7].being = player;
//	tower->floors[0].grid[1][12].being = player;

	printf("makeTheTower checkpoint 3\n");
	printf("player ptr A: %p\n",player);
	Being_print(*player);

//	printf("player stance: %c\n",first_floor.grid[0][0].being->stance);

//	Board second_floor = Board_new("Second floor",15,15);

//	tower->floors[1] = second_floor;


	printf("test\n");

//	tower.

	printf("makeTheTower ended\n");
	return tower;
}
