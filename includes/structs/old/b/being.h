#ifndef UTT_BEING_H
#define UTT_BEING_H

#include "thing.h"

//so this should all work now..
typedef struct {
	Thing thing;//do I know whats acutally happening here??
/*
	Thing {

	char  display_char;
	char  stance;
	Being *being }

*/

	int strength;//hit damage and health
	int haste;//accuracy and dodge
	int wit;//magic and trap discovery

	int hp;//health
	int sp;//stamina
	int mp;//mana

} Being;
/*
Being Being_load(char *save_file_name){
	FILE *save_file;
	save_file = fopen(save_file_name,"r");

	if (save_file == NULL) {
		Being being = {
			'!',
			'!',//error stance
			1,
			0,0,0,0,0,0

		};

		return being;
	}

	int size_of_everything_but_display_image = 26;

	char save[size_of_everything_but_display_image];

	fgets(save,size_of_everything_but_display_image,save_file);

//	char display_image[16];
//	fgets(display_image,16,save_file);

//	Being being = (Being)malloc(sizeof(Being));

//	printf("%d",

	int stats[6] = {0,0,0,0,0,0};
	for (int i=0;i<6;i+=1){
		stats[i] = ((int) (save[i*4+2]     )
			   +(int) (save[i*4+3] << 8)
			   +(int) (save[i*4+3] <<16)
			   +(int) (save[i*4+3] <<24));
	}
// from Being_save:
//		save[i*4 +2] = (char) (stats[i]);
//		save[i*4 +3] = (char) (stats[i] >>  8);
//		save[i*4 +4] = (char) (stats[i] >> 16);
//		save[i*4 +5] = (char) (stats[i] >> 24);


//old code (doesnt work)
/*		for (int j=3;j>=0;j--){
			stats[i] +=  save[i*4+j+2];
			stats[i] <<= 8;
		}*/
/*
	Being being = {

		(char)save[0],
		(char)save[1],
		1,//type: shows that this is a being
	//	display_image,

		stats[0],
		stats[1],
		stats[2],
		stats[3],
		stats[4],
		stats[5]

	};

	fclose(save_file);

	return being;
};

void Being_save(char*save_file_name,Being being){
	if (being.thing.stance != '!') {

		int size_of_everything_but_display_image = 26;
		char save[size_of_everything_but_display_image];

		save[0] = being.thing.display_char;
		save[1] = being.thing.stance;

		int stats[6] = {being.strength,
				being.haste,
				being.wit,
				being.hp,
				being.sp,
				being.mp};

//		printf("%i%i%i%i%i%i",stats[0],stats[1],stats[2],stats[3],stats[4],stats[5]);

		for (int i=0;i<6;i++) {
			save[i*4 +2] = (char) (stats[i]);
			save[i*4 +3] = (char) (stats[i] >>  8);
			save[i*4 +4] = (char) (stats[i] >> 16);
			save[i*4 +5] = (char) (stats[i] >> 24);
//old code (it might work?)
//(the error I was trying to solve was actually with Being_read)
//			for (int j=0;j<4;j++) {
//				save[2 + 4*i + j] = (char) (stats[i] >> (8*(3-j)));
//			}
		}


		FILE *save_file;
		save_file = fopen(save_file_name,"w");

/* //(debug) read the bytes before saving
		printf("0:%c",save[0]);
		printf("1:%c",save[1]);
	        for (int i=2;i<26;i++){
	                printf("%d:%d\n",i,save[i]);
	        }


		for (int i=0;i<26;i++){
			fputc(save[i],save_file);
		}
	        fclose(save_file);


	}
}
*/
void Being_print(Being being){
	printf("character: %c\n",being.thing.display_char);
	printf("stance: %c\n",being.thing.stance);
	printf("strength: %d\n",being.strength);
	printf("haste: %d\n",being.haste);
	printf("wit: %d\n",being.wit);
	printf("HP: %d\n",being.hp);
	printf("SP: %d\n",being.sp);
	printf("MP: %d\n",being.mp);
}

#endif
