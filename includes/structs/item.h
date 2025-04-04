#ifndef UTT_ITEM_H
#define UTT_ITEM_H

#include "use.h"

typedef struct {
	char *name;
	char *description;
	int number_of_uses;//NOT durability!
	Use *uses;
	char *slot;
} Item;

Item Item_new(char *name,char *desc,int n,const Use *uses) {
	Item new_item = {name,desc,n};

	new_item.uses = (Use*)malloc(sizeof(Use)*n);

	if (uses != (Use*)NULL) {
		for (int i=0;i<n;i++) {
			new_item.uses[i] = uses[i];
		}
	}
	return new_item;
}

/*
Item *Item_new(char *name,char *desc,int n,const Use *uses) {
	Item *new_item = (Item*)malloc(sizeof(Item));
	new_item->name = name;
	new_item->description = desc;
	new_item->number_of_uses = n;

	new_item->uses = (Use*)malloc(sizeof(Use)*n);
	if (uses != (Use*)NULL) {
		for (int i=0;i<n;i++) {
			new_item->uses[i] = uses[i];
	}	}
	return new_item;
}
*/

/*
Item *Item_clone(Item *item) {


}
*/


#endif
