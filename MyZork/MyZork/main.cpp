#include "world.h"
#include <stdio.h>

int main() {

	World My_World;

	CreateWorld(My_World.room, My_World.exit);

	do{
		Look(My_World);
	} while (Play(My_World.exit, My_World.player));

	getchar();
	return 0;
}