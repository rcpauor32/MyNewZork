#include "world.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	bool EXIT = 1;

	World My_World;

	My_World.player.current_room = Surgery;
	CreateWorld(My_World.room, My_World.exit);

	Look(My_World.room, My_World.player);

	while (EXIT){
		EXIT = Play(My_World);
	}

	printf("\nThanks for Playing :D");

	delete My_World.room;
	delete My_World.exit;

	getchar();
	return 0;
}