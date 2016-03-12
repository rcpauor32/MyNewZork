#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#define NUM_ROOM 11
#define NUM_EXITS 10

enum room_name {
	Secret,
	Surgery,
	UpAngel,
	DwAngel,
	Studio,
	Stone,
	Mirror,
	Waiting,
	Reception,
	Library,
	Dark
};

enum exit_name {
	SectoSur,
	SurtoUpA,
	UpAtoStu,
	UpAtoDwA,
	DwAtoSto,
	DwAtoWai,
	DwAtoLib,
	StotoMir,
	WaitoRec,
	LibtoDar
};

enum directions {
	north,
	south,
	west,
	east,
	up,
	down
};

#endif