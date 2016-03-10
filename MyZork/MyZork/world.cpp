#include "world.h"
#include "rooms.h"
#include "globals.h"

void CreateWorld(Rooms room[NUM_ROOM]) {
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

}