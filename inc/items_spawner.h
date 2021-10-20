#ifndef ITEMS_SPAWNER_H
#define ITEMS_SPAWNER_H

#include "spawner.h"
#include "healing_potion.h"
#include "rage_potion.h"
#include "ironskin_potion.h"

class ItemsSpawner: public Spawner {
public:
	void spawn() const;
	ItemsSpawner(GameField& game_field);
};

#endif