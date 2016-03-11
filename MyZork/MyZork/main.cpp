#include "exits.h"
#include "globals.h"
#include "rooms.h"
#include "world.h"
#include "player.h"
#include <stdio.h>

int main() {
	World My_World;

	CreateWorld(My_World.room, My_World.exit);

	printf("  - %s\n\n %s", My_World.room[player.current_room].name, My_World.room[player.current_room].description);

	scanf_s("%s", &player.input);


	getchar();
	return 0;
}