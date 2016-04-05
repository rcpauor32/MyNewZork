#ifndef _EXITS_H_
#define _EXITS_H_

#include "entities.h"

class Links : public Entity {
public:
	int previous_room;
	int next_room;
	char* dir_proom;
	char* dir_nroom;
	bool open = 1;

	void CreateLinks(int room1, char* dir1, int room2, char* dir2, bool open_state){
		previous_room = room1;
		next_room = room2;
		dir_proom = dir1;
		dir_nroom = dir2;
		open = open_state;
	}

};

#endif