#ifndef UTT_TILE_H
#define UTT_TILE_H

#include "thing.h"

typedef struct {
	char display_char;
	Thing   *thing;
//	Item    *item;
//	Effect  *effect;

} Tile;

int Tile_addBeing(Tile *tile,Thing *thing){
        if (tile->thing == 0){
        printf("it is zero\n");
        }
        tile->thing = thing;
	printf("'%c' vs '%c'\n",tile->display_char,thing->display_char);
        tile->display_char = thing->display_char;
	printf("'%c' vs '%c'\n",tile->display_char,thing->display_char);
        return 0;
}



Tile blank_tile = {' '};
Tile wall_tile  = {'#'};

#endif
