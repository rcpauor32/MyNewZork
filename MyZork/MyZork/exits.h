#ifndef _EXITS_H_
#define _EXITS_H_

class Links {
public:
	int previous_room;
	int next_room;
	char* dir_proom;
	char* dir_nroom;

	void CreateLinks(int room1, char* dir1, int room2, char* dir2){
		previous_room = room1;
		next_room = room2;
		dir_proom = dir1;
		dir_nroom = dir2;
	}

};

#endif