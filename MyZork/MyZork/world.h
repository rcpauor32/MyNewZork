#ifndef _WORLD_H_
#define	_WORLD_H_

#include "exits.h"
#include "rooms.h"
#include "globals.h"

struct World {
	Rooms room[NUM_ROOM];

};

void CreateWorld(Rooms room[NUM_ROOM]);

#endif