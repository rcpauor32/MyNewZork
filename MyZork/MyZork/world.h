#ifndef _WORLD_H_
#define	_WORLD_H_

#include "exits.h"
#include "rooms.h"
#include "globals.h"
#include "player.h"

class Rooms;
class Exits;
class Player;
class Entity;

class World {
public:
	virtual ~World();

	Rooms* room = new Rooms[NUM_ROOM];
	Links* exit = new Links[NUM_EXITS];
	Players player;
};

void CreateWorld(Rooms room[NUM_ROOM], Links exit[NUM_EXITS]);

bool Play(World (&world));
void Look(Rooms* room, Players player);
void Go(World (&world), char* direction);
void OpenClose(World (&world), char* action, char* direction);

#endif