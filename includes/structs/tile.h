#ifndef UTT_TILE_H
#define UTT_TILE_H

#include "being.h"

typedef struct {
	Being *being;
	int sight_level;//0 == unseen, 1 == in sight, 2 == previously seen
} Tile;

void Tile_freeParts(Tile tile) {
//	printf("%ld,%ld\n",sizeof(tile.being),sizeof(*tile.being));
	if (sizeof(*tile.being) > 8) {
		Being_free(tile.being);
	};
}

#endif
