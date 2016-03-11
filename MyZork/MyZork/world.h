#ifndef _WORLD_H_
#define	_WORLD_H_

#include "exits.h"
#include "rooms.h"
#include "globals.h"
#include "player.h"

class Rooms;
class Exits;

class World {
public:
	Rooms* room = new Rooms[NUM_ROOM];
	Links* exit = new Links[NUM_EXITS];
	Players player;

	~World();
};

void CreateWorld(Rooms room[NUM_ROOM], Links exit[NUM_EXITS]);

bool Play(Links exit[NUM_EXITS], Players player);
void Look(World My_World);

#endif