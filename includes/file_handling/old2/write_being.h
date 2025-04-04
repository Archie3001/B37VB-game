#ifndef UTT_WRITE_BEING_H
#define UTT_WRITE_BEING_H

#include "write_stats.h"
#include "parse_strings.h"



void writeBeing(FILE *save_file,Being *being) {
	if (being == (Being*)NULL) {
		fputc('F',save_file);
	} else {
		fputc('T',save_file);

		fputc(being->display_char,save_file);
		fputc(being->stance,save_file);

//		printf("%d,%d\n",size1,size2);
//		printf("%c%s%c%s\n",(char)sizeof(being->name)-1,being->name,(char)sizeof(being->image_name)-1,being->image_name);
//		fprintf(save_file,"%c%s%c%s",getStringLength(being->name),being->name,getStringLength(being->image_name),being->image_name);
//		printf("%d%s%d%s\n",getStringLength(being->name),being->name,getStringLength(being->image_name),being->image_name);

		writeString(save_file,being->name);
		writeString(save_file,being->image_name);
		writeStats(save_file,being->stats);
	}



}

#endif
