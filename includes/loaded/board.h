#ifndef UTT_PARSE_BOARD_GRID_STRING_H
#define UTT_PARSE_BOARD_GRID_STRING_H

#include <stdio.h>

void Board_gridTextRead(Board *board,const char *grid_string) {
	int index=0;//for the grid_string
	int ix=0,iy=0;//for the grid

	printf("size: %ld\n",sizeof(grid_string));

	printf("test: %p\n",board->grid[14][13].being);
	printf("test: %p\n",board->grid[0][14].being);
	printf("test: %p\n",board->grid[1][14].being);
	printf("test: %p\n",board->grid[2][14].being);

	while (iy < board->y) {
		switch(grid_string[index]) {
		case '#':
//			if (iy < 14) {
			printf("#");
//			} else {
//			printf("# %d,%d\n",ix,index);
//			}
			board->grid[iy][ix].being = &WALL;
			ix++;
			break;
		case ' ':
//			if (iy < 14) {
			printf(" ");
//			} else {
//			printf(". %d,%d\n",ix,index);
//			}
			board->grid[iy][ix].being = &AIR;
			ix++;
			break;
		case '\n':
//			if (iy < 14) {
			printf("\n");
//			} else {
//			printf("n %d\n",ix);
//			}
			break;
		case '/':
			printf("/");
			board->grid[iy][ix].being = &DOOR;//Being_clone(&DOOR);
			ix++;
			break;
		case '^':
			printf("^");
			board->grid[iy][ix].being = &STAIR_UP;
			ix++;
			break;
		case 'v':
			printf("v");
			board->grid[iy][ix].being = &STAIR_DOWN;
			ix++;
//			printf("%d,%d;%c,%c",ix,iy,board->grid[iy][ix].being->display_char,board->grid[iy][ix].being->stance);
			break;
		default:
			printf("!");
			board->grid[iy][ix].being = &AIR;
			ix++;
//			printf("unexpected character '%c' at: %d,%d,%d\n",grid_string[index],index,ix,iy);
		}
		if (ix == board->x) {// && grid_string[index+1] != '\n') {
			printf("\n");
			ix = 0;
			iy ++;
		}
//		printf("ix:%d iy:%d i:%d c:%d/'%c'\n",ix,iy,index,grid_string[index],grid_string[index]);
		index++;
	}
	printf("\n");

//	Board_print(*board);
}

void Board_readGridFile(Board *board,char *file_name) {
	FILE *file = fopen(file_name,"r");
	char buffer[64] = {0};
	char grid_string[(board->x + 1)*board->y];
	printf("size_of_string: %ld\n",sizeof(grid_string));

	if (!file) {
		fclose(file);
		printf("file not found \"%s\"\n",file_name);
		return;
	}


	int found_symbol = 0, i;
	while (fgets(buffer,sizeof(buffer),file) && !found_symbol) {
		for (i=0;i<sizeof(buffer);i++) {
			if (buffer[i] == ':') {
				found_symbol = 1;
				break;
			} else if (buffer[i] == '\n') {
				break;
			}
		}
	//	if (found_symbol) { break; }
		printf("found: %d, at %d\n",found_symbol,i);
		printf("buffer: %s",buffer);
	}

	printf("found: %d, at %d\n",found_symbol,i);
	printf("buffer: %s",buffer);

	for (int i=0;i<board->x+1;i++) {
		grid_string[i] = buffer[i];
	}
	//(grid_string,board->x+2,buffer);

	for (int i=board->x+1;i<sizeof(grid_string);i+=board->x+1) {
		fgets(grid_string + i,board->x+2,file);
		printf(": %s",grid_string + i);
	}
	printf("grid_string: \n%s\n",grid_string);

	Board_gridTextRead(board,grid_string);

	fclose(file);
}

/*
void Board_readGridFile(Board *board,char *file_name) {
	FILE *file = fopen(file_name,"rt");
	printf("file ptr: %p\n",file);

	if (!file) {
		return;
	}

	int max_line_size = board->x + 2;
	int line_number   = 0;
	int end_of_block  = 1;
	int i_grid_string = 0;
	char line[max_line_size];
	char grid_string[(max_line_size)*board->y];
/*	printf("test\n");
//	fscanf(file,"%s:\n",floor_number);
	///%s,",floor_number,grid_string);
	printf("test\n");
	printf("test1 (%d)\n",sizeof(line));
	fgets(line,6,file);
	printf("test2\n");
	printf("%s\n",line);
	while (fgets(line,max_line_size,file) && !end_of_block) {
		printf("line: %s\n",line);
		int i;
		for (i=0;i<max_line_size;i++) {
			if (line[i] == ',') {
				end_of_block = 1;
			}
			grid_string[i_grid_string+i] = line[i];
		}
//		printf("%s\n",line);
		i_grid_string += max_line_size;
	}
	Board_gridTextRead(board,grid_string);

	fclose(file);
}
*/
#endif
