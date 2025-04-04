#ifndef UTT_READ_STATS_C
#define UTT_READ_STATS_C

#include "../structs/stats.h"
#include "test_exists.h"
#include "parse_int.h"

#include "../display/stats.h"

Stats *readStats(FILE *save_file){

	char save[STATS_SAVE_LENGTH];
	fread(save,1,STATS_SAVE_LENGTH,save_file);

	int stat_values[NUMBER_OF_STATS];

	int stat_index = 0;
	for (int i=0;i<STATS_SAVE_LENGTH;i+=INT_SAVE_SIZE) {
		stat_values[stat_index] = charsToIntFromIndex(save,i);
		printf("read stat: %d\n",stat_values[stat_index]);
		stat_index ++;
	}

	Stats *stats = malloc(sizeof(Stats));

	stats = Stats_build (
		stat_values[0],
		stat_values[1],
		stat_values[2],
		stat_values[3],
		stat_values[4],
		stat_values[5]
	);

	return stats;
}

#endif
