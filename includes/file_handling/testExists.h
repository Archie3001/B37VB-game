#ifndef UTT_FILE_TEST_EXISTS_H
#define UTT_FILE_TEST_EXISTS_H

#include <stdio.h>

int testExists(FILE *file) {
	char exists = fgetc(file);
	if (exists = 'T') {
		return 1;
	} else {
		return 0;
	}
}

void writeExists(FILE *file, void* thing) {
	if (thing == (void*)NULL) {
		fputc('F',file);
	} else {
		fputc('T',file);
	}
}

#endif
