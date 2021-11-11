#ifndef SPAWNER_H
#define SPAWNER_H

#include "game_field.h"

class Spawner {
protected:
	GameField* game_field;
public:
	virtual ~Spawner(){};
	virtual void spawn() const = 0;
};

#endif