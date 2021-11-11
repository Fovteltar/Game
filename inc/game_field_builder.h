#ifndef GAME_FIELD_BUILDER_H
#define GAME_FIELD_BUILDER_H

#include <cstdlib>
#include <utility>
#include <cstddef>
#include <ctime>

#include "game_field.h"

#include "player_spawner.h"
#include "enemies_spawner.h"
#include "items_spawner.h"

class GameFieldBuilder { 
private:
	GameField* game_field;
public:
	void buildSF();
	void buildField();
	void buildCreatures();
	void reset();
	~GameFieldBuilder();
	GameFieldBuilder(const std::pair<size_t, size_t>& field_size);
	GameField* getGameField();
};

#endif