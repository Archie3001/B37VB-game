#ifndef UTT_DISPLAY_STATS_H
#define UTT_DISPLAY_STATS_H

#include "../../structs/use.h"

void Use_print(Use use) {
	printf("%s: %d\n",use.usecase,use.power);
};




#endif
