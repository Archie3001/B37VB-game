#ifndef UTT_WRITE_TILE_H
#define UTT_WRITE_TILE_H

#include "write_being.h"




Tile *writeTile(FILE *save_file,Tile *tile) {
	writeBeing(save_file,tile->being);
}

#endif
