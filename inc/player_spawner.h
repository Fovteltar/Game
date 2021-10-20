#ifndef PLAYER_SPAWNER_H
#define PLAYER_SPAWNER_H

#include "spawner.h"
#include "player.h"

class PlayerSpawner: public Spawner {
public:
	void spawn() const;
	PlayerSpawner(GameField& game_field);
};

#endif