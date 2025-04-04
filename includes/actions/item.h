#ifndef UTT_ITEM_ACTIONS_H
#define UTT_ITEM_ACTIONS_H

#include <string.h>


//int Item_checkSlot(Item *item,char *slot) {
//	int valid = 1;
//	return valid;
//}

int Item_getWeaponDamage(Item *item,Being *being) {
	int damage = 0;
	for (int i=0; i<item->number_of_uses; i++) {

		if (!strcmp(item->uses[i].usecase,slash.usecase)) {
			damage += (item->uses[i].power)
					*((being->stats->str >> 0)
					+ (being->stats->hst >> 2)
					+ (being->stats->wit >> 1));
		} else if (!strcmp(item->uses[i].usecase,bash.usecase)) {
			damage += (item->uses[i].power)
					*((being->stats->str >> 0)
					+ (being->stats->hst >> 1)
					+ (being->stats->wit >> 2));
		} else if (!strcmp(item->uses[i].usecase,stab.usecase)) {
			damage += (item->uses[i].power)
					*((being->stats->str >> 2)
					+ (being->stats->hst >> 1)
					+ (being->stats->wit >> 0));
		} else if (!strcmp(item->uses[i].usecase,venom.usecase)) {
			damage += (item->uses[i].power)
					*((being->stats->str >> 3)
					+ (being->stats->hst >> 3)
					+ (being->stats->wit << 1));
		}
	}
	return damage;
}

int Item_getArmourDefense(Item *item) {
	int defense = 0;
	for (int i=0; i<item->number_of_uses; i++) {



	}

	return defense;
}


#endif
