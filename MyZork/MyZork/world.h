#ifndef _WORLD_H_
#define	_WORLD_H_

#include "exits.h"
#include "rooms.h"
#include "globals.h"

class World {
public:
	Rooms* room = new Rooms[NUM_ROOM];
	Exits* exit = new Exits[NUM_EXITS];

	~World();
};

void CreateWorld(Rooms room[NUM_ROOM], Exits exit[NUM_EXITS]);


#endif