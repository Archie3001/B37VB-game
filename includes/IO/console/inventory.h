#ifndef UTT_CONSOLE_INVENTORY_H
#define UTT_CONSOLE_INVENTORY_H

void Inventory_print(const Inventory *inventory){
	const Inventory inv = *inventory;
	printf("Inventory:\n");
	if (inv.belt) {
		printf("Belt:\n");
		for (int i=0; inv.belt[i]; i++) {
			Item_print(inv.belt[i]);
		}
	}
	if (inv.bag) {
		printf("Bag:\n");
		for (int i=0; inv.bag[i]; i++) {
			Item_print(inv.bag[i]);
		}
	}
}



#endif
