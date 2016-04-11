#ifndef __ENITIES_H__
#define __ENITIES_H__

#include "my_string.h"
enum entity_type {
	ROOM,
	EXIT,
	PLAYER
};

class Entity {
public:
	Entity();
	virtual ~Entity();

public:
	entity_type type;

};



#endif