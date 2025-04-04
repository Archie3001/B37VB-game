#ifndef UTT_BEING_H
#define UTT_BEING_H

#include "stats.h"
#include "inventory.h"

typedef struct { //Being
	char display_char;
	char stance;
	char *name;
//	char *image_name; //not yet
//	???? *image;
	Stats *stats;//may be null
	Inventory *inventory;//may be null
} Being;


Being *Being_new(char display_char, char stance, char *name) {
	Being *being = (Being*)malloc(sizeof(Being));
	being->display_char = display_char;
	being->stance = stance;
	being->name = name;
	being->stats = (Stats*)NULL;
	being->inventory = (Inventory*)NULL;
	return being;
}

Being *Being_clone(const Being *other_being) {
	Being *new_being = (Being*)malloc(sizeof(Being));
	*new_being = *other_being;
	return new_being;
	}


Being
	AIR        = {' ',' ',"air"		,NULL,NULL},
	WALL       = {'#','#',"wall"		,NULL,NULL},
	DOOR       = {'/','/',"door"		,NULL,NULL},
	STAIR_UP   = {'^','^',"stair up"	,NULL,NULL},
	STAIR_DOWN = {'v','v',"stair down"	,NULL,NULL};

void Being_freeParts(Being being) {
	if (being.stats) {
//		printf("stats?\n");
		free(being.stats);
	}
	if (being.inventory) {
//		printf("inv?\n");
		Inventory_free(being.inventory);
	}
}

void Being_free(Being *being) {
	if (being != &AIR
	&&  being != &WALL
	&&  being != &DOOR
	&&  being != &STAIR_UP
	&&  being != &STAIR_DOWN
	) {
	Being_freeParts(*being);
	free(being);
	}
}


#endif
