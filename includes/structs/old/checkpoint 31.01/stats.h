#ifndef UTT_STATS_H
#define UTT_STATS_H

const int NUMBER_OF_STATS = 6;

//#include "../file_handling/parse_int.h"
//const int STATS_SAVE_LENGTH = NUMBER_OF_STATS * INT_SAVE_SIZE;

typedef struct { //Stats
	int str;
	int hst;
	int wit;

	int hp;
	int sp;
	int mp;
} Stats;

Stats Stats_new(int str,int hst,int wit,int hp,int sp,int mp) {
	Stats stats = {str,hst,wit,hp,sp,mp};
	return stats;
}
/*
int *Stats_toInts(Stats stats) {
	int *stat_values = (int*)malloc(sizeof(int)*NUMBER_OF_STATS);

	stat_values[0] = stats.str;
	stat_values[1] = stats.hst;
	stat_values[2] = stats.wit;
	stat_values[3] = stats.hp;
	stat_values[4] = stats.sp;
	stat_values[5] = stats.mp;

	return stat_values;
}

*/
#endif
