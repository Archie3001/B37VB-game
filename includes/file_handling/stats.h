#ifndef UTT_FILE_STATS_H
#define UTT_FILE_STATS_H

#include <stdlib.h>
#include <stdio.h>
#include "../structs/stats.h"

Stats *Stats_read(FILE *file) {
	static Stats stats;
	fscanf(file,"%d,%d,%d,%d,%d,%d,",
		&stats.str,
		&stats.hst,
		&stats.wit,
		&stats.hp,
		&stats.sp,
		&stats.mp);

	return &stats;
}

void Stats_write(FILE *file,Stats stats) {
	fprintf(file,"%d,%d,%d,%d,%d,%d,",
		stats.str,
		stats.hst,
		stats.wit,
		stats.hp,
		stats.sp,
		stats.mp);
}

#endif
