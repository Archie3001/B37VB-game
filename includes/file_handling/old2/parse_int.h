#ifndef UTT_PARSE_INT_H
#define UTT_PARSE_INT_H

#include <stdio.h>
#include <stdlib.h>

const int INT_SAVE_SIZE = 4;

int charsToInt(char *int_string) {
	int number;
	for (int i=0;i<INT_SAVE_SIZE;i++) {
		number <<= 8;
		number  += int_string[i];
	}
	return number;
}

int charsToIntFromIndex(char *int_string,int starting_index) {
	int number;
	const int end = INT_SAVE_SIZE + starting_index;
	for (int i=starting_index;i<end;i++) {
		number <<= 8;
		number  += int_string[i];

	}
//	printf("%d\n",number);
	return number;
}

char* intToChars(int number) {
	char *int_string = (char*) malloc(sizeof(char)*(INT_SAVE_SIZE));

	for (int i=INT_SAVE_SIZE-1;i>=0;i++) {
		int_string[i] = (char) number;
		number >>= 8;
	}

	return int_string;
}

void saveInt(FILE *save_file,int number) {
	for (int i=(INT_SAVE_SIZE-1)*8;i>=0;i-=8) {
//		printf("%d\n",(char) (number >> i));
		fputc((char) (number >> i),save_file);
	}
}


/*
void saveInt(FILE *save_file,int number) {
//
//	for (int i=0;i<INT_SAVE_SIZE;i++) {
//		printf("%d\n",(char)number);
//		fputc((char)(number/(8*(INT_SAVE_SIZE-1))),save_file);
//		number <<= 8;
//	}
}

/*void saveInt(FILE *save_file,char *int_string) {
	for (int i=INT_SAVE_SIZE-1;i>=0;i++) {
		fputc(int_string[i],save_file);
	}
}

/*
//whoops, it was c++ that had function overloading

void saveInt(FILE *save_file,int number) {
	save_int(save_file,int_to_chars(number));
}*/

int readInt(FILE *save_file) {
	int number;
	for (int i=0;i<INT_SAVE_SIZE;i++) {
		number <<= 8;
		number  += fgetc(save_file);
	}
	printf("%d\n",number);
	return number;
}


#endif
