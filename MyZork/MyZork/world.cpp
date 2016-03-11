#include "world.h"
#include "rooms.h"
#include "globals.h"

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

int GetNumArgs(char* string) {
	int n_args = 1;

	while (string) {
		if (*string == ' ') {
			n_args++;
		}
		string++;
	}

	return n_args;
}

char* GetArgs(char* string, int n_string) {
	int n_arg = 1;
	char* Arg;
	int Arg_size = sizeof(Arg);

	while (string) {
		if (*string == ' ')
			n_arg++;
		if (n_arg == n_string) {
			while (*string != ' ' || string){
				*Arg = *string;
				Arg++;
				string++;
			}
		}

		string++;
	}

	Arg -= Arg_size;

	return Arg;
}

World::~World() {
	delete room;
	delete exit;
}