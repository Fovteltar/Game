#ifndef SPAWNER_H
#define SPAWNER_H

#include "game_object.h"
#include "game_field.h"

class Spawner {
public:
	virtual ~Spawner(){};
	virtual void spawn() const = 0;
};

#endif