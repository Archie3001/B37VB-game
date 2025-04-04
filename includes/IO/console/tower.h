#ifndef UTT_PRINT_TOWER_H
#define UTT_PRINT_TOWER_H

#include "board.h"

void Tower_print(const Tower tower) {
	for (int i=0; i < tower.height; i++) {
		Board_print(tower.floors[i]);
	}

}


#endif
