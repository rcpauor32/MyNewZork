#include "world.h"
#include "rooms.h"
#include "globals.h"
#include <string.h>
#include <stdio.h>

World::~World() {
}

void CreateWorld(Rooms room[NUM_ROOM], Links exit[NUM_EXITS]) {
	room[Secret].CreateRooms("Secret Room", "This is a dark room only lighted up by the fading light of your torch.\n After a moment you realize there is a man-like hooded figure standing in a corner.\n He doesn't seem to have noticed you yet.\n The only visible door is to the SOUTH.\n");
	room[Surgery].CreateRooms("Surgery Room", "You just see a surgery bed in the center of the room.\n All the walls of this octogonal room seem really old, dark and burned.\n There's a big CLOSED door on the SOUTH wall. \n Also, you see a crack on the NORTH wall big enough to fit in.\n");
	room[UpAngel].CreateRooms("Upstairs Angel Room", "You are in a 'doughnut' shaped room.\n To the WEST there's a door with a sign that reads 'Studio' and a Surgery room-like door at the NORTH.\n You look downwards through the centric hole. There's a human like statute of an angel.\n Seems like you could go DOWN through the stairs that are at your right and left.\n");
	room[DwAngel].CreateRooms("Downstairs Angel Room", "You've reached the angel at the center of the room.\n From here you realize it has no head and this makes it a lot creepier.\n You are in a round room with doors to the WEST, SOUTH and EAST and stairs to go UP.\ Maybe you should investigate.\n");
	room[Studio].CreateRooms("Studio", "You are in a little room with just a fading light on a desk full of drawers.\n On the EAST wall there's a door.\n");
	room[Stone].CreateRooms("Stone Room", "This room is all made of living stone.\n You realize that in a corner there's a woman like statue which is hidding her face behinf her hands.\n There's a cristal door to the SOUTH and a wooden door on the EAST wall.\n");
	room[Mirror].CreateRooms("Mirror Room", "The room walls are literally made of mirrors that can reflect everything in the room.\n The only exit you can see is to the NORTH.\n");
	room[Waiting].CreateRooms("Waiting Room", "This is a plain but creepily empty waiting room from a very old hospital.\n There is an exit to the SOUTH and another to the NORTH");
	room[Reception].CreateRooms("Reception", "You came up in a reception from a hospital.\n There is a big white door with a sign on top that read 'EXIT' but it seems to be completly jammed.\n The only viable door on the room is to the NORTH.\n");
	room[Library].CreateRooms("Library", "You are in a huge Library plenty of old books.\n There's a table with a kid notebook and an old newspaper.\n You see a door in a dark corner to the SOUTH and a wooden door the WEST.\n");
	room[Dark].CreateRooms("Dark Room", "Everything is dark.\n The blackness seems to be draining your torch's light since it can just light up little more than your feet.\n The only viable exit (apart from the infinite darkness) is a door to the NORTH.\n");

	exit[SectoSur].CreateLinks(Secret, "south", Surgery, "north", true);
	exit[SurtoUpA].CreateLinks(Surgery, "south", UpAngel, "north", false);
	exit[UpAtoStu].CreateLinks(UpAngel, "west", Studio, "east", false);
	exit[UpAtoDwA].CreateLinks(UpAngel, "down", DwAngel, "up", true);
	exit[DwAtoSto].CreateLinks(DwAngel, "west", Stone, "east", true);
	exit[DwAtoWai].CreateLinks(DwAngel, "south", Waiting, "north", true);
	exit[DwAtoLib].CreateLinks(DwAngel, "east", Library, "west", true);
	exit[StotoMir].CreateLinks(Stone, "south", Mirror, "north", true);
	exit[WaitoRec].CreateLinks(Waiting, "south",Reception, "north", true);
	exit[LibtoDar].CreateLinks(Library, "south", Dark, "north", true);

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