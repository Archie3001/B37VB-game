#ifndef UTT_TOWER
#define UTT_TOWER

#include "board.h"


typedef struct {
	int floors;
	Board* boards;
} Tower;

Tower Tower_load(save_file_name){
	FILE *save_file;
	save_file = fopen(save_file_name,"r");

	if (save_file == NULL){
		return NULL;
	}

	//header {name,floors}
	//board\n
	//...
	//board\n

	Board

}



#endif
