#ifndef UTT_INVENTORY_H
#define UTT_INVENTORY_H

#include "item.h"

typedef struct {
	Item *weapon;
	Item **belt;
	Item **bag;
} Inventory;

Inventory *Inventory_new(int belt_size,int bag_size) {
	Inventory *inventory;
	inventory->weapon = (Item*)NULL;
	inventory->belt = (Item**)malloc(sizeof(Item*)*belt_size);
	inventory->bag = (Item**)malloc(sizeof(Item*)*bag_size);
	return inventory;
}

#endif
