#ifndef UTT_FILE_THING_C
#define UTT_FILE_THING_C

#include <stdio.h>

Thing *Thing_load(FILE *save_file) {
	char save[3];
	fread(save,1,3,save_file);
	Thing thing = malloc(sizeof(Thing));
	Thing thing = {save[0],save[1],save[2]};//will this work??//maybe????
	//I genuinely cant remember if this works or not
	return &thing;
}


int Thing_save(FILE *save_file,Thing thing) {
	char save[3] = {thing.display_char,thing.stance};
	if (thing.being == NULL) {
		save[3] = ';';
	} else {
		save[3] = ',';
	}
	f.write(save,1,2,save_file);
	return 0;
}

#endif
