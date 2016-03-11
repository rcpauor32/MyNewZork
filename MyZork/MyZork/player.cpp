#include "exits.h"
#include "globals.h"


int Go(int& current_room, char* player_direction, Links exit[NUM_EXITS]) {
	int success = 0;

	for (int n_exit = 0; n_exit < NUM_EXITS; n_exit++)	 {
		if (exit[n_exit].previous_room == current_room && exit[n_exit].dir_nroom == player_direction) {
			current_room = exit[n_exit].next_room;
			success = 1;
		}
		else 
			if (exit[n_exit].next_room == current_room && exit[n_exit].dir_proom == player_direction) {
			current_room = exit[n_exit].previous_room;
			success = 1;
		}
	}	

	return success;
}



