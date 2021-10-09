#ifndef GAME_FIELD_BUILDER_H
#define GAME_FIELD_BUILDER_H

#include "game_field.h"
#include "igame_field_builder.h"

#include <cstdlib>
#include <utility>
#include <cstddef>
#include <ctime>

class GameFieldBuilder: public IGameFieldBuilder { 
private:
	GameField* game_field;
public:
	void buildSE();
	void buildField();
	void reset();
	~GameFieldBuilder();
	GameFieldBuilder(std::pair<size_t, size_t> field_size);
	GameField* getGameField();
};

#endif