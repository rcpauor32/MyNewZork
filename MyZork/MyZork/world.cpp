#include "world.h"
#include "rooms.h"
#include "globals.h"
#include <string.h>
#include <stdio.h>

void CreateWorld(Rooms room[NUM_ROOM], Links exit[NUM_EXITS], Players player) {
	room[Secret].CreateRooms("Secret Room", "Secret description");
	room[Surgery].CreateRooms("Surgery Room", "Surgery description");
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

	player.Init_player(Surgery);

}

bool Play(Links exit[NUM_EXITS], Players player) {
	char input[20];
	char second_input[20];
	printf("Action:\n\n--> ");
	fgets(input, 20, stdin);
	if ((strcmp(input, "quit\n") == 0) || strcmp(input, "q\n") == 0)
		return false;
	else {
		if (!strcmp(input, "north\n") || !strcmp(input, "n\n")) {
			Go(player.current_room, "north", exit);
		}
		else if (!strcmp(input, "south\n") || !strcmp(input, "s\n")) {
			Go(player.current_room, "south", exit);
		}
		else if (!strcmp(input, "west\n") || !strcmp(input, "w\n")) {
			Go(player.current_room, "west", exit);
		}
		else if (!strcmp(input, "east\n") || !strcmp(input, "e\n")) {
			Go(player.current_room, "east", exit);
		}
		else if (!strcmp(input, "up\n") || !strcmp(input, "u\n")) {
			Go(player.current_room, "up", exit);
		}
		else if (!strcmp(input, "down\n") || !strcmp(input, "d\n")) {
			Go(player.current_room, "down", exit);
		}
		else  
			if (strcmp(input, "go\n") == 0) {
				printf("\nWhere?\n\n--> ");
				fgets(second_input, 20, stdin);
				if (!strcmp(second_input, "north\n") || !strcmp(second_input, "n\n")) {
					Go(player.current_room, "north", exit);
				}
				else if (!strcmp(second_input, "south\n") || !strcmp(second_input, "s\n")) {
					Go(player.current_room, "south", exit);
				}
				else if (!strcmp(second_input, "west\n") || !strcmp(second_input, "w\n")) {
					Go(player.current_room, "west", exit);
				}
				else if (!strcmp(second_input, "east\n") || !strcmp(second_input, "e\n")) {
					Go(player.current_room, "east", exit);
				}
				else if (!strcmp(second_input, "up\n") || !strcmp(second_input, "u\n")) {
					Go(player.current_room, "up", exit);
				}
				else if (!strcmp(second_input, "down\n") || !strcmp(second_input, "d\n")) {
					Go(player.current_room, "down", exit);
				}
				else{
					printf("I do not recognize that direction");
					getchar();
				}
			}
			else
				if (!strcmp(input, "open door\n")) {
					if (exit[player.current_room].open) {
						printf("\nThe door was already open\n");
					}
					else {
						printf("\nYou opened the door\n");
						exit[player.current_room].open = true;
					}
				}
				else
					if (!strcmp(input, "close door\n")) {
						if (!exit[player.current_room].open) {
							printf("\nThe door was already closed\n");
						}
						else {
							printf("\nYou closed the door\n");
							exit[player.current_room].open = false;
						}
					}
					else
						if (!strcmp(input, "open\n")) {
							printf("\nWhat:\n\n--> ");
							fgets(second_input, 20, stdin);
							if (!strcmp(second_input, "door\n")){
								if (exit[player.current_room].open) {
									printf("\nThe door was already open\n");
								}
								else {
									printf("\nYou opened the door\n");
									exit[player.current_room].open = true;
								}
							}
						}
						else
							if (!strcmp(input, "close\n")) {
								printf("\nWhat:\n\n--> ");
								fgets(second_input, 20, stdin);
								if (!strcmp(second_input, "door\n")){
									if (!exit[player.current_room].open) {
										printf("\nThe door was already closed\n");
									}
									else {
										printf("\nYou closed the door\n");
										exit[player.current_room].open = true;
								
									}
								}
								else
									printf("I don't know that object.\n");
							}
							
			else {
				printf("I do not recognize that action");
				getchar();
			}
	}

	return true;
}

World::~World() {
	delete room;
	delete exit;
}

void Look(Rooms* room, Players player) {
	printf("  - %s\n\n %s\n\n", room[player.current_room].name, room[player.current_room].description);

}