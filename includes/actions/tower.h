#ifndef UTT_TOWER_ACTIONS_H
#define UTT_TOWER_ACTIONS_H

int Tower_ascend (Tower *tower,int *current_floor) {

	//if current_floor is top floor or above

	printf("tower:%d\nfloor:%d\n",*current_floor,tower->height);
	if (*current_floor + 1 >= tower->height) {
		//say it's the top
		return 1;//minor error
	}//else {

	//local variables
	Player player;
	int *staircase;

	//get pointer to the player
	player = tower->floors[*current_floor].player;
	//clear the player from this floor
	tower->floors[*current_floor].player.being = (Being*)NULL;
	tower->floors[*current_floor].grid[player.x][player.y].being = &AIR;

	//ascend
	(*current_floor) ++;

	//find the staircase
	staircase = Board_findBeingOfStance (&tower->floors[*current_floor],'v');
	if (staircase[0] < 0) {
		//staircase wasn't found
		return 2;//major error
	}//else {

	//place the player
	player.x = staircase[0];
	player.y = staircase[1];
	tower->floors[*current_floor].player = player;
	tower->floors[*current_floor].grid[player.x][player.y].being = player.being;

	return 0;//successful
}

void Tower_descend (Tower *tower,int *current_floor) {

}


#endif
