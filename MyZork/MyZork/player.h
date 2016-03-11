#ifndef	 _PLAYER_H_
#define	 _PLAYER_H_

class Players {
public:
	int current_room = Surgery;

};

int Go(int &current_room, char* player_direction, Links exit[NUM_EXITS]);

#endif