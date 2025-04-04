#ifndef UTT_THING_H
#define UTT_THING_H

typedef struct {
	char display_char;
	char stance;
	Being *being;// NULL if not linked to a being
//	char display_image;

} Thing;

/*
int Thing_addToTile(Tile tile,Thing thing){
	if (tile.thing == 0){
	printf("it is zero");
	}
	tile.thing = &thing;
	tile.display_char = thing.display_char;
	return 0;
}*/
/*
Thing wall = {'#','#'};
Thing air  = {' ',' '};
Thing door = {'-','-'};
*/
#endif
