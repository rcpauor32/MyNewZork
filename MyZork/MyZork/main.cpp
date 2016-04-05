#include "world.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

	bool EXIT = 1;

	World My_World;

	My_World.player.current_room = Surgery;
	CreateWorld(My_World.room, My_World.exit);

	printf("\n\nWelcome To Zork: Dark Sleep: The walking/door opener simulator.\n\nIn this prototype you can:\n  MOVE BETWEEN ROOMS USING -->\n   'go north/south/east/west/up'\n   'north/south/east/west/up/down'\n   'n/s/e/w/u/d\n\n OPEN/CLOSE DOORS USING -->\n   'open/close door' and then 'north/south/east/west' or 'n/s/e/w'\n\n  QUIT :'C\n   'quit' or 'q'\n\nReady?\nPress any key!\n");
	getchar();
	system("CLS");
	printf("\n\nYou have awaken in a dark room, when you eyes start to see, you realize is an odd and old Surgery room.\nWhat are you doing here?\n\n");

	Look(My_World.room, My_World.player);

	while (EXIT){
		EXIT = Play(My_World);
	}

	printf("\nThanks for Playing :D");

	getchar();
	return 0;
}