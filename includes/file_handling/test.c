#include "being.h"
#include <stdio.h>

int main() {
	Stats statblock = {
		1,
		2,
		3,
		4,
		5,
		6
	};

	FILE *writefile = fopen("test_file","rt");

	Stats_write(writefile,statblock);

	fclose(writefile);
}
