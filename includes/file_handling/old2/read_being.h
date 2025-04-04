#ifndef UTT_READ_BEING_C
#define UTT_READ_BEING_C

#include "read_stats.h"
#include "../structs/being.h"
#include "test_exists.h"
#include "parse_strings.h"

Being readBeing(FILE *save_file) {

	Being being;
	char save[2], *name, *display_image_name;
	int size_of_next_value;

	fread(save,1,2,save_file);

	being.display_char = save[0];
	being.stance = save[1];

//	fscanf(save_file,"%s%s",name,display_image_name);

//	size_of_next_value = fgetc(save_file);
///	name = (char*)malloc(size_of_next_value);
//	fread(name,1,size_of_next_value,save_file);
	being.name = readString(save_file);


//	size_of_next_value = fgetc(save_file);
//	printf("%c",(char)size_of_next_value);
//	display_image_name = (char*)malloc(size_of_next_value);
//	fread(display_image_name,1,size_of_next_value,save_file);
	being.image_name = readString(save_file);


	if (testExists(save_file)) {
//		Stats stats = readStats(save_file);
//		being.stats = malloc(sizeof(Stats));
		being.stats = readStats(save_file);
		Stats *stats = being.stats;
	} else {
		being.stats = (Stats*) NULL;
	}

	Stats_print(being.stats);
	return being;
}


#endif
