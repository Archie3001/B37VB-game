#ifndef UTT_PRINT_ITEM_H
#define UTT_PRINT_ITEM_H

#include "use.h"
#include "../../structs/item.h"

void Item_print(const Item *item_ptr) {
	const Item item = *item_ptr;
	printf("%s:\n%s\n",item.name,item.description);
	for (int i=0;i<item.number_of_uses;i++) {
		Use_print(item.uses[i]);
	}
}


#endif
