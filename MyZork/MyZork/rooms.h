#ifndef	_ROOMS_H_
#define	_ROOMS_H_

class Rooms : public Entity {
public:
	char* name;
	char* description;

	void CreateRooms(char* title, char* desc) {
		name = title;
		description = desc;
	}
};

#endif