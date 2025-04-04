#ifndef UTT_WRITE_TOWER_H
#define UTT_WRITE_TOWER_H

#include "write_board.h"

void writeTower(FILE *save_file, Tower *tower){
	writeString(save_file,tower->name);
	saveInt(save_file,tower->height);
	for (int i=0;i<tower->height;i++) {
		writeBoard(save_file,&tower->floors[i]);
	}
}

#endif
