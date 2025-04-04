#ifndef UTT_PARSE_STRINGS_H
#define UTT_PARSE_STRINGS_H

int getStringLength(char* string) {

        int i;
        for (i=0;string[i] != '\0'; i++){}
        return i;
}

char *readString(FILE *save_file) {
	int length = fgetc(save_file);
	char *string = (char*)malloc(length+1);
	fread(string,1,length,save_file);
	return string;
}

void writeString(FILE *save_file,char* string) {
	fputc(getStringLength(string),save_file);
	fprintf(save_file,"%s",string);
}

#endif
