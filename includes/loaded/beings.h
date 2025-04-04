#ifndef UTT_BEINGS_WRITTEN_H
#define UTT_BEINGS_WRITTEN_H

#include "../structs/being.h"
#include "items.h"

Being *define_beings (Item *items) {

	int number_of_beings = 1;

	Being *beings = (Being*)malloc(sizeof(Being)*number_of_beings);

	beings[0].display_char = 's';
	beings[0].stance = 'E';
	beings[0].name = "snake";
	Stats_set(&beings[0].stats,1,2,3,4,5,6);
	Inventory_set(&beings[0].inventory,1,1);
	beings[0].inventory->belt[0] = &items[0];
	beings[0].inventory->bag[0] = &items[3];


//	printf("P1: %p\n",beings[0].stats);

	printf("test\n");
	return beings;
}

//const Use FANGS = {"stab",()NULL,-1};
//const Use CLAWS = {"blade",()NULL,-1};

//Inventory

//Being SNAKE = {'s','E',"snake",Stats_new(6,10,4,6,10,4),}


#endif
