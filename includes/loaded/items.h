#ifndef UTT_ITEMS_H
#define UTT_ITEMS_H

#include "../structs/item.h"
#include "uses.h"

Item *define_items() {

	int number_of_items = 5;

	Item *items = (Item*)malloc(sizeof(Item)*number_of_items);

	//snake fangs
	items[0] = Item_new("snake fangs","A pair of fangs with small holes in the tips.",3,(Use*)NULL);
	items[0].uses[0]       = stab;
	items[0].uses[0].power = 2;
	items[0].uses[1]       = venom;
	items[0].uses[1].power = 6;
	items[0].uses[2]       = dear;
	items[0].uses[2].power = 10;
	items[0].slot = "weapon";

	//copper shortsword
	items[1] = Item_new("copper shortsword","An orange blade with a leather wrapped handle.",2,(Use*)NULL);
	items[1].uses[0]       = slash;
	items[1].uses[0].power = 10;
	items[1].uses[1]       = stab;
	items[1].uses[1].power = 6;
	items[1].slot = "weapon";

	//boiled leather chestplate
	items[2] = Item_new("leather chestplate","Boiled leather sheets sewed together with cord to form a chestplate.",1,NULL);
	items[2].uses[0]       = torso;
	items[2].uses[0].power = 10;
	items[2].slot = "chestplate";

	//snakeskin
	items[3] =  Item_new("snake skin","Scaled skin from a snake",1,NULL);
	items[3].uses[0]       = dear;
	items[3].uses[0].power = 10;
	items[3].slot = NULL;

	return items;
}









/*
Item
	*snake_fangs = ,


end_of_items;

snake_fangs->uses[0] = stab;
snake_fangs->uses[1] = venom;
snake_fangs->uses[2] = dear;

printf("N:%s\nD:%s\nn:%d\n",snake_fangs->name,snake_fangs->description,snake_fangs->number_of_uses);
}
*/
#endif
