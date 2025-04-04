#ifndef UTT_GAME_LOOP_H
#define UTT_GAME_LOOP_H "console"


#include "tower.h"
#include "misc.h"
#include "../../.actions.h"//player.h"

char getCharFromUser() {
//	printf("input: ");
	char user_input_char='\n';
	while (user_input_char == '\n') {
		scanf("%c",&user_input_char);
	}
	return user_input_char;
};

int game_loop(Tower tower) {

	//init
	int running = 1;
	int current_floor = 0;
	char char_input;
	char move_output;

	int *stairs_down_pos = NULL;
	int *stairs_up_pos   = NULL;

	printf("Welcome to Up The Tower.\n");
	printf("enter 'h' or '?' if you need help.\n");
	printf("You are exploring %s\n",tower.name);

	Board_print(tower.floors[current_floor]);


	while (running) {
		//get user input
		char_input = getCharFromUser();

//		printf("input: %c\n",char_input);

		//give output
		switch (char_input) {
		case 'h':
		case '?':
			printf("%s",help_string);
			break;
		case 'w':
			move_output = Player_move(-1,0,&tower.floors[current_floor]);
			Board_print(tower.floors[current_floor]);
			break;
		case 'a':
			move_output = Player_move(0,-1,&tower.floors[current_floor]);
			Board_print(tower.floors[current_floor]);
			break;
		case 's':
			move_output = Player_move(1,0,&tower.floors[current_floor]);
			Board_print(tower.floors[current_floor]);
			break;
		case 'd':
			move_output = Player_move(0,1,&tower.floors[current_floor]);
			Board_print(tower.floors[current_floor]);
			break;
		case ' ':
			Board_tick(tower.floors[current_floor],1);
			Board_print(tower.floors[current_floor]);
			break;
		case 'q':
			printf("Quit game? enter 'y' to confirm\n");
			char_input = getCharFromUser();
			if (char_input == 'y') {
				printf("quitting...\n");
				running = 0;
			} else {
				printf("continuing...\n");
			}
			break;
		case 'l':
			Board_print(tower.floors[current_floor]);
			break;
		default:
			printf("your input was not recognised, enter 'h' or '?' for help\n");
			break;
		}

		switch(move_output) {
		case '^':
			//ascend
			move_output = Tower_ascend(&tower,&current_floor);
			switch(move_output) {

			case 0:
				//display the new floor
				Board_print(tower.floors[current_floor]);
				break;
			case 1:
				//display victory message
//				victory(tower);
				printf("its over\n");
				running = 0;
				break;
			default:
				printf("(default)\n");
			case 2:
				//uh oh
				printf("Uh oh: ascent problem\n");
				break;
			}
			break;
		case 'v':
//			maka the staircase down
			Tower_descend(&tower,&current_floor);
			current_floor --;
			stairs_up_pos = Board_findBeingOfStance(&tower.floors[current_floor],'^');
			Board_print(tower.floors[current_floor]);
			move_output = ' ';
			break;
		default:
			break;
		}

//		if (current_floor == tower.height) {
//			running = 0;
//			Victory(tower,player);
//		}
	}

	printf("goodbye\n");
	return 0;
};

#endif
