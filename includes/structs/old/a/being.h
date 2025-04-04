#ifndef UTT_BEING_H
#define UTT_BEING_H


struct Being {
	char stance;//eg: 'P' = player controlled, 'X' = impassible(like a wall)
	//more stances in documents/stances.txt
	char  display_char;//char representation of this being
	char* display_image;//link to bitmap image in the image folder
	//stats

	int vis;//vision: affects senses and spells and is max mp
	int str;//strength: affects attack and is max hp
	int spd;//speed: affects time taken for actions and is max sp

	int hp;//health points: needed for staying alive
	int mp;//mana points: needed for magic actions
	int sp;//stamina points: needed for physical actions
};


#ifndef NULL_CHAR
char NULL_CHAR = '\0';
#endif
struct Being NO_BEING = {' ',' ',&NULL_CHAR,0,0,0,0,0,0};

#endif

