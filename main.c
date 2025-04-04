#include <stdio.h>
#include <stdlib.h>

#include "includes/.structs.h"
#include "includes/loaded/the_tower.h"
#include "includes/IO/console/game_loop.h"


int main()
{
	printf("Sizes of items:\n");
	printf("Tower - %ld\n",sizeof(Tower));
	printf("Board - %ld\n",sizeof(Board));
	printf("Tile  - %ld\n",sizeof(Tile ));
	printf("Being - %ld\n",sizeof(Being));
	printf("Stats - %ld\n",sizeof(Stats));

	Tower *tower = makeTheTower();
//	printf("Player stance: %c\n",tower->floors[0].grid[0][0].being->stance);
//	printf("Player ptr M: %p\n",tower->floors[0].player.being);

//	Board_print(tower.floors[0]);

	game_loop(*tower);

//	Tower_print(*tower);

	Tower_free(tower);

//	printf("pointer: %p\n",tower.floors[0].grid[0][0]);

//	Board test_board = Board_build(3,4);

//	printf("%c",test_board.grid[0][0].display_char);

//	Being snake = Load_Being("saves/beings/snake");

//	Tile_addBeing(&test_board.grid[1][2],&snake.thing);

//	printf("%c",(test_board.grid[1][2]).display_char);

//	printf("%c,%d,%d,%d,%d,%d,%d\n",snake.thing.stance,snake.haste,snake.strength,snake.wit,snake.sp,snake.hp,snake.mp);

//	Board_print(test_board);


	return 0;
}
