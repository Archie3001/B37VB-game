#ifndef UTT_TOWER_H
#define UTT_TOWER_H

#include "board.h"

typedef struct {
	char *name;
	int height;
	Board *floors;
} Tower;


Tower Tower_new(char *name,int height){
	Tower tower = {name,height};

	//mhm, malloc sizeof(Board), not sizeof(Board*)
	tower.floors = (Board*)malloc(sizeof(Board));

	return tower;
}

void Tower_free(Tower *tower) {
	for (int i=0; i<tower->height; i++) {
		Board_free( tower->floors[i] );
	}
	free(tower);
}


#endif
