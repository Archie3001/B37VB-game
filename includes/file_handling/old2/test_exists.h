#ifndef UTT_TEST_EXISTS_C
#define UTT_TEST_EXISTS_C

#include <stdio.h>

int testExists(FILE *save_file) {
	char exists;
	fread(&exists,1,1,save_file);
	if (exists == 'T') {
		return 1;
	} else {
		return 0;
	}
}

#endif
