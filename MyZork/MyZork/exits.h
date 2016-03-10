#ifndef _EXITS_H_
#define _EXITS_H_

struct Exits {
	const int previous_room;
	const int next_room;
	const char* dir_proom;
	const char* dir_nroom;
};

#endif