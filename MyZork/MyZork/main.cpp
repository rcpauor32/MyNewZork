#include "world.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	World My_World;

	CreateWorld(My_World.room, My_World.exit, My_World.player);

	do{
		system("CLS");
		Look(My_World.room, My_World.player);
	} while (Play(My_World.exit, My_World.player));

	printf("\nThanks for Playing :D");

	getchar();
	return 0;
}