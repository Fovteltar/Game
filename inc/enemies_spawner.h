#ifndef ENEMIES_SPAWNER_H
#define ENEMIES_SPAWNER_H

#include "spawner.h"
#include "shadow_warrior.h"
#include "killer_ant.h"
#include "spider.h"

class EnemiesSpawner: public Spawner {
public:
	void spawn() const;
	EnemiesSpawner(GameField& game_field);
};

#endif