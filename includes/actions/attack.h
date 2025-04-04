#ifndef UTT_ATTACK_H
#define UTT_ATTACK_H

#include <stdlib.h>
#include <string.h>
#include "item.h"

int Being_attack(Board *board,int * attacker_pos,int * attacked_pos) {
	//this function trusts the inputs
	//for now at least

	Being
		*attacker = board->grid[attacker_pos[0]][attacker_pos[1]].being,
		*attacked = board->grid[attacked_pos[0]][attacked_pos[1]].being;

	int
		attack_power = 0,
		defense_power = 0,
		dodge_chance = 0;


	for (int i=0; attacker->inventory->belt; i++) {
		if (!strcmp(attacker->inventory->belt[i]->slot,"weapon")) {
//		if (Item_checkSlot(attacker->inventory->belt[i],"weapon") ) {
			attack_power += Item_getWeaponDamage(attacker->inventory->belt[i],attacker);
		}
	}

	for (int i=0; attacked->inventory->belt; i++) {
		if (!strcmp(attacker->inventory->belt[i]->slot,"armour")) {
//		if (Item_checkSlot(attacked->inventory->belt[i],"armour") ) {
			defense_power += Item_getArmourDefense(attacked->inventory->belt[i]);
		}
	}

	attack_power -= defense_power;
	if (attack_power <= 0) {
		attack_power = 1;
	}

	dodge_chance += attacked->stats->hst + attacked->stats->wit/2;
	dodge_chance *= 4;
	dodge_chance /= attacker->stats->hst * attacker->stats->wit;

	printf("attack: %d\n",attack_power);
	printf("dodge: %d\n",dodge_chance);

//	if (rand() % dodge_chance) {
//
//	}

	return 0;
}


#endif
