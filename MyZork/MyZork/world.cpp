#include "world.h"
#include "rooms.h"
#include "globals.h"
#include <string.h>
#include <stdio.h>

void CreateWorld(Rooms room[NUM_ROOM], Links exit[NUM_EXITS]) {
	room[Secret].CreateRooms("Secret Room", "Secret description");
	room[Surgery].CreateRooms("Surgery Room", "You just see a surgery bed in the center of the room.\nAll the walls of this octogonal room seem really old, dark and burned.\nThere's a big CLOSED door on the SOUTH wall. \nAlso, you see a crack on the NORTH wall big enough to fit in.\n");
	room[UpAngel].CreateRooms("Upstairs Angel Room", "UpA desc");
	room[DwAngel].CreateRooms("Downstairs Angel Room", "DwA desc");
	room[Studio].CreateRooms("Studio", "Studio desc");
	room[Stone].CreateRooms("Stone Room", "Stone desc");
	room[Mirror].CreateRooms("Mirror Room", "Mirror desc");
	room[Waiting].CreateRooms("Waiting Room", "Waiting desc");
	room[Reception].CreateRooms("Reception", "Reception desc");
	room[Library].CreateRooms("Library", "Library desc");
	room[Dark].CreateRooms("Dark Room", "Dark desc");

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

bool Play(World (&world)) {
	char input[20];
	printf("\n\n--> ");
	fgets(input, 20, stdin);
	if ((strcmp(input, "quit\n") == 0) || strcmp(input, "q\n") == 0)
		return false;
	else {
		if (!strcmp(input, "north\n") || !strcmp(input, "n\n") || !strcmp(input, "go north\n")) {
			Go(world, "north");
		}
		else if (!strcmp(input, "south\n") || !strcmp(input, "s\n") || !strcmp(input, "go south\n")) {
			Go(world, "south");
		}
		else if (!strcmp(input, "west\n") || !strcmp(input, "w\n") || !strcmp(input, "go west\n")) {
			Go(world, "west");
		}
		else if (!strcmp(input, "east\n") || !strcmp(input, "e\n") || !strcmp(input, "go east\n")) {
			Go(world, "east");
		}
		else if (!strcmp(input, "up\n") || !strcmp(input, "u\n") || !strcmp(input, "go up\n")) {
			Go(world, "up");
		}
		else if (!strcmp(input, "down\n") || !strcmp(input, "d\n") || !strcmp(input, "go down\n")) {
			Go(world, "down");
		}
		else if (!strcmp(input, "open door\n")) {
			printf("Which one?\n\n--> ");
			fgets(input, 20, stdin);
			if (!strcmp(input, "north\n") || !strcmp(input, "n\n"))
				OpenClose(world, "open", "north");
			else if (!strcmp(input, "south\n") || !strcmp(input, "s\n"))
				OpenClose(world, "open", "south");
			else if (!strcmp(input, "west\n") || !strcmp(input, "w\n"))
				OpenClose(world, "open", "west");
			else if (!strcmp(input, "east\n") || !strcmp(input, "e\n"))
				OpenClose(world, "open", "east");
			else if (!strcmp(input, "up\n") || !strcmp(input, "u\n"))
				OpenClose(world, "open", "up");
			else if (!strcmp(input, "down\n") || !strcmp(input, "d\n"))
				OpenClose(world, "open", "down");
			else
				printf("I do not recognize that door");
		}
		else
			if (!strcmp(input, "close door\n")) {
				printf("Which one?\n\n--> ");
				fgets(input, 20, stdin);
				if (!strcmp(input, "north\n") || !strcmp(input, "n\n"))
					OpenClose(world, "close", "north");
				else if (!strcmp(input, "south\n") || !strcmp(input, "s\n"))
					OpenClose(world, "close", "south");
				else if (!strcmp(input, "west\n") || !strcmp(input, "w\n"))
					OpenClose(world, "close", "west");
				else if (!strcmp(input, "east\n") || !strcmp(input, "e\n"))
					OpenClose(world, "close", "east");
				else if (!strcmp(input, "up\n") || !strcmp(input, "u\n"))
					OpenClose(world, "close", "up");
				else if (!strcmp(input, "down\n") || !strcmp(input, "d\n"))
					OpenClose(world, "close", "down");
				else
					printf("I do not recognize that door");
		}
		else {
			printf("I do not recognize that action\n");
		}
	}

	return true;
}

void Look(Rooms* room, Players player) {
	printf("  - %s\n\n %s", room[player.current_room].name, room[player.current_room].description);

}


void Go(World (&world), char* direction) {
	bool success = 0;

	for (int i = 0; i < NUM_EXITS; i++) {
		if (world.player.current_room == world.exit[i].next_room && world.exit[i].dir_nroom == direction) {
			success = 1;
			if (!world.exit[i].open){
				printf("\nThat door is closed, try opening it.\n");
			}
			else {
				world.player.current_room = world.exit[i].previous_room;
				Look(world.room, world.player);
			}
		}
		if (world.player.current_room == world.exit[i].previous_room && world.exit[i].dir_proom == direction && !success) {
			success = 1;
			if (!world.exit[i].open){
				printf("\nThat door is closed, try opening it.\n");
			}
			else {
				world.player.current_room = world.exit[i].next_room;
				Look(world.room, world.player);
			}
		}
	}

	if (!success)
		printf("\nThere's nothing on that direction\n");
}

void OpenClose(World (&world), char* action, char* direction) {
	
	for (int i = 0; i < NUM_EXITS; i++) {
		if (world.player.current_room == world.exit[i].next_room && world.exit[i].dir_nroom == direction) {
			if (world.exit[i].open && action == "open")
				printf("\nThis door is already open\n");
			else if (!world.exit[i].open && action == "open"){
				printf("\nYou've opened the door\n");
				world.exit[i].open = 1;
			}
			else if (!world.exit[i].open && action == "close")
				printf("\nThis door is already closed\n");
			else if (world.exit[i].open && action == "close") {
				printf("\nYou've closed the door\n");
				world.exit[i].open = 0;
			}
		}
		if (world.player.current_room == world.exit[i].previous_room && world.exit[i].dir_proom == direction) {
			if (world.exit[i].open && action == "open")
				printf("\nThis door is already open\n");
			else if (!world.exit[i].open && action == "open"){
				printf("\nYou've opened the door\n");
				world.exit[i].open = 1;
			}
			else if (!world.exit[i].open && action == "close")
				printf("\nThis door is already closed\n");
			else if (world.exit[i].open && action == "close") {
				printf("\nYou've closed the door\n");
				world.exit[i].open = 0;
			}
		}
	}

}