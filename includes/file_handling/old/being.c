#ifndef UTT_FILE_BEING_LOAD_C
#define UTT_FILE_BEING_LOAD_C

#include <stdio.h>
#include "../structs/being.h"

Being Being_load(FILE save_file,Thing thing) {
	if (save_file == NULL) {
		return NULL;
	}

	char save[24];
	fread(save,1,26,save_file);

        int stats[6] = {0,0,0,0,0,0};
        for (int i=0;i<6;i+=1){
                stats[i] = ((int) (save[i*4]     )
                           +(int) (save[i*4+1] << 8)
                           +(int) (save[i*4+2] <<16)
                           +(int) (save[i*4+3] <<24));
	}

        Being being = {
	        thing,
	        stats[0],
	        stats[1],
	        stats[2],
	        stats[3],
	        stats[4],
	        stats[5]
	};
	return being;
}

void Being_save(FILE *save_file Being_being){
	Thing_save(save_file,being.thing);

	int stats[6] = {being.strength,being.haste,being.wit,being.hp,being.sp,being.mp};
	char save[24];
	for (int i=0;i<6;i++){

                (save[i*4]	= (char)(stat[i]);
                (save[i*4+1]    = (char)(stat[i] >> 8);
                (save[i*4+2]    = (char)(stat[i] >>16);
                (save[i*4+3]    = (char)(stat[i] >>24));
/*from Being_load(FILE *...);
                stats[i] = ((int) (save[i*4]     )
                           +(int) (save[i*4+1] << 8)
                           +(int) (save[i*4+2] <<16)
                           +(int) (save[i*4+3] <<24));
*/
	}
}


#endif
