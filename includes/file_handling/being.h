#ifndef UTT_FILE_BEING_H
#define UTT_FILE_BEING_H

#include <stdlib.h>
#include <stdio.h>
#include "stats.h"
#include "testExists.h"
#include "../structs/being.h"

Being Being_read(FILE *file) {
	Being being;
	being.display_char = fgetc(file);
	being.stance       = fgetc(file);
	fscanf(file,"\"%s\"",being.name);

	if (testExists(file)) {
		being.stats = (Stats*)malloc(sizeof(Stats));
		being.stats = Stats_read(file);
	} else {
		being.stats = (Stats*) NULL;
	}
	return being;
}

//void Being_write(FILE *file,Being being) {
//	if (Being.stats == )


//}

#endif
