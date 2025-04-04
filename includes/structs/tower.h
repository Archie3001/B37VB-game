#ifndef UTT_TOWER_H
#define UTT_TOWER_H

#include "board.h"

typedef struct {
	char *name;
	int height;
	Board *floors;
} Tower;


Tower *Tower_new(char *name,int height){
//	Tower tower = {name,height};
	Tower *tower = (Tower*)malloc(sizeof(Tower));
	tower->name = name;
	tower->height = height;

	//mhm, malloc sizeof(Board), not sizeof(Board*)
	tower->floors = (Board*)malloc(sizeof(Board)*height);

	return tower;
}

void Tower_freeParts(Tower tower) {
	for (int i=0; i<tower.height; i++) {
		Board_freeParts( tower.floors[i] );
	}
}

void Tower_free(Tower *tower) {
	Tower_freeParts(*tower);
	free(tower);
}


#endif

