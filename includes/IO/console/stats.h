#ifndef UTT_PRINT_STATS_H
#define UTT_PRINT_STATS_H


void Stats_print(const Stats *stats_ptr) {
//	printf("test\n");
	const Stats stats = *stats_ptr;
//	printf("P4: %p\n",stats_ptr);
	printf("Stats:\nSTR:%d\nHST:%d\nWIT:%d\nHP:%d\nSP:%d\nMP:%d\n",stats.str,stats.hst,stats.wit,stats.hp,stats.sp,stats.mp);
}


#endif
