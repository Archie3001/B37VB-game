#ifndef UTT_READ_TILE_H
#define UTT_READ_TILE_H

#include "../structs/tile.h"
#include "read_being.h"

Tile readTile(FILE *save_file) {
	Tile tile;
	if (testExists(save_file)) {
		Being being = readBeing(save_file);
		tile.being = &being;
	} else {
		tile.being = (Being*) NULL;
	}

	if (tile.being != (Being*)NULL) {
		Stats_print(tile.being->stats);
	}
	return tile;
}

#endif
