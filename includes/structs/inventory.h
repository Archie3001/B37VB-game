#ifndef UTT_INVENTORY_H
#define UTT_INVENTORY_H

#include "item.h"

typedef struct {
	Item **belt;//null terminated
	Item **bag;//null terminated
} Inventory;

void Inventory_set(Inventory **inventory,int belt_size,int bag_size) {
	*inventory = (Inventory*)malloc(sizeof(inventory));

	if (belt_size) {
		(*inventory)->belt = (Item**)malloc(sizeof(Item*)*(belt_size+1));
		(*inventory)->belt[belt_size] = (Item*)NULL;
	} else {
		(*inventory)->belt = (Item**)NULL;
	}

	if (belt_size) {
		(*inventory)->bag  = (Item**)malloc(sizeof(Item*)*(bag_size+ 1));
		(*inventory)->bag [bag_size ] = (Item*)NULL;
	} else {
		(*inventory)->bag = (Item**)NULL;
	}

/*
	if (belt_size > 0) {
		(*inventory)->belt = (Item**)malloc(sizeof(Item*)*(belt_size+1));
		(*inventory)->belt[belt_size] = (Item*)NULL;
	} else {
		(*inventory)->belt = (Item**)NULL;
	}

	if (bag_size > 0) {
		(*inventory)->bag = (Item**)malloc(sizeof(Item*)*bag_size);
		(*inventory)->bag[bag_size] = (Item*)NULL;
	} else {
		(*inventory)->belt = (Item**)NULL;
	}
*/
}

void Inventory_freeParts(Inventory inv) {
	if (inv.belt) {
		free(inv.belt);
	}
	if (inv.bag) {
		free(inv.bag);
	}
}

void Inventory_free(Inventory *inv) {
	Inventory_freeParts(*inv);
	free(inv);
}

#endif
