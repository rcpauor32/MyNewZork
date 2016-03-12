#ifndef	 _PLAYER_H_
#define	 _PLAYER_H_

class Players {
public:
	int current_room = Surgery;

	void Init_player(int starting_room){
		current_room = starting_room;
	}

};

void Go(int &current_room, char* player_direction, Links* exit);

#endif