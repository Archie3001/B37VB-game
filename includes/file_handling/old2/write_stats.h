#ifndef WRITE_STATS_C
#define WRITE_STATS_C

#include "parse_int.h"
#include "../structs/stats.h"

void writeStats(FILE *save_file,Stats *stats) {
	if (stats == (Stats*)NULL) {
		fputc('F',save_file);
	} else {
		fputc('T',save_file);

		int *stat_values = Stats_toInts(*stats);
		for (int i=0;i<NUMBER_OF_STATS;i++) {
			printf("writ stat: %d\n",stat_values[i]);
			saveInt(save_file,stat_values[i]);
		}//end for
	}//end if
}//end writeStats(...)

#endif
