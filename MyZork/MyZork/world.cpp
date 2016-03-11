#include "world.h"
#include "rooms.h"
#include "globals.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void CreateWorld(Rooms room[NUM_ROOM], Links exit[NUM_EXITS]) {
	room[Secret].name = "Secret Room";
	room[Surgery].name = "Surgery"; 
	room[UpAngel].name = "Upstairs Angel Room";
	room[DwAngel].name = "Downstairs Angel Room";
	room[Studio].name = "Studio";
	room[Stone].name = "Stone Room";
	room[Mirror].name = "Mirror Room";
	room[Waiting].name = "Waiting Room";
	room[Reception].name = "Reception";
	room[Library].name = "Library";
	room[Dark].name = "Dark Room";

	room[Secret].description = "secretdescription";
	room[Surgery].description = "surgerydesc";
	room[UpAngel].description = "upangeldesc";
	room[DwAngel].description = "downangeldesc";
	room[Studio].description = "studiodesc";
	room[Stone].description = "stonedesc";
	room[Mirror].description = "mirrordesc";
	room[Waiting].description = "waitingdesc";
	room[Reception].description = "receptiondesc";
	room[Library].description = "librarydesc";
	room[Dark].description = "darkdesc";

	for (int n_room = 0; n_room < NUM_ROOM; n_room++) {
		room[n_room].room_num = n_room;
	}

	exit[SectoSur].CreateLinks(Secret, "south", Surgery, "north");
	exit[SurtoUpA].CreateLinks(Surgery, "south", UpAngel, "north");
	exit[UpAtoStu].CreateLinks(UpAngel, "west", Studio, "east");
	exit[UpAtoDwA].CreateLinks(UpAngel, "down", DwAngel, "up");
	exit[DwAtoSto].CreateLinks(DwAngel, "west", Stone, "east");
	exit[DwAtoWai].CreateLinks(DwAngel, "south", Waiting, "north");
	exit[DwAtoLib].CreateLinks(DwAngel, "east", Library, "west");
	exit[StotoMir].CreateLinks(Stone, "south", Mirror, "north");
	exit[WaitoRec].CreateLinks(Waiting, "south",Reception, "north");
	exit[LibtoDar].CreateLinks(Library, "south", Dark, "north");

}

bool Play(Links exit[NUM_EXITS], Players player) {
	char input[20];
	char dir_input[20];
	printf("Action:\n\n--> ");
	fgets(input, 20, stdin);
	if ((strcmp(input, "quit\n") == 0) || strcmp(input, "q\n") == 0)
		return false;
	else
		if (strcmp(input, "go\n") == 0) {
			printf("\n\nWhere?\n--> ");
			fgets(dir_input, 20, stdin);
			if (!strcmp(dir_input, "north\n") || !strcmp(dir_input, "n\n")) {
				if (!Go(player.current_room, "north", exit))
					printf("\n\nYou just smashed your head against the wall!");
			}
			else if (!strcmp(dir_input, "south\n") || !strcmp(dir_input, "s\n")) {
				if (!Go(player.current_room, "south", exit))
					printf("\n\nYou just smashed your head against the wall!");
			}
			else if (!strcmp(dir_input, "west\n") || !strcmp(dir_input, "w\n")) {
				if (!Go(player.current_room, "west", exit))
					printf("\n\nYou just smashed your head against the wall!");
			}
			else if (!strcmp(dir_input, "east\n") || !strcmp(dir_input, "e\n")) {
				if (!Go(player.current_room, "east", exit))
					printf("\n\nYou just smashed your head against the wall!");
			}
			else if (!strcmp(dir_input, "up\n") || !strcmp(dir_input, "u\n")) {
				if (!Go(player.current_room, "up", exit))
					printf("\n\nYou just smashed your head against the ceiling!");
			}
			else if (!strcmp(dir_input, "down\n") || !strcmp(dir_input, "d\n")) {
				if (!Go(player.current_room, "down", exit))
					printf("\n\nYou just smashed your head against the floor!");
			}
			else
				printf("I do not recognize that direction");
		}
		else
			printf("I do not recognize that action");

	return true;
}

World::~World() {
	delete room;
	delete exit;
}

void Look(World My_World) {
	system("CLS");
	printf("  - %s\n\n %s\n\n", My_World.room[My_World.player.current_room].name, My_World.room[My_World.player.current_room].description);

}