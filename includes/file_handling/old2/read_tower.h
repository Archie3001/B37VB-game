#ifndef UTT_READ_TOWER_H
#define UTT_READ_TOWER_H

#include "read_board.h"
#include "../structs/tower.h"

Tower readTower(FILE *save_file) {
	Tower tower;
	tower.name = readString(save_file);
	tower.height = readInt(save_file);
	tower.floors = (Board*)malloc(sizeof(Board)*tower.height);
	for (int i=0;i<tower.height;i++) {
		tower.floors[i] = readBoard(save_file);
	}
	return tower;
}

#endif
