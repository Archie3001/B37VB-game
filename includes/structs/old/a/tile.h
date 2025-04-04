#ifndef UTT_TILE_H
#define UTT_TILE_H

//#include "puddle.h"
//#include "air.h"
#include "being.h"
//#include "item.h"

struct Tile {
	//struct Puddle *puddle;
	//struct Air    *air;
	struct Being  *being;
	//struct Item   *item;
};

//const Tile BLANK_TILE {*NO_PUDDLE,*CLEAR_AIR,*NO_BEING,*NO_ITEM};
struct Tile BLANK_TILE = {&NO_BEING};

#endif
