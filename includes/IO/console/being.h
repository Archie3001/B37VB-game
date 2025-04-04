#ifndef UTT_PRINT_BEING_H
#define UTT_PRINT_BEING_H

#include "stats.h"
#include "inventory.h"
//#include "does it work?"

void Being_print(const Being being) {
	printf("%s '%c'[%c]:\n",being.name,being.display_char,being.stance);
	if (being.stats) {
		Stats_print(being.stats);
	}
	if (being.inventory) {
		Inventory_print(being.inventory);
	}
}



#endif
