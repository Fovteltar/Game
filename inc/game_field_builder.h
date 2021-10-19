#ifndef GAME_FIELD_BUILDER_H
#define GAME_FIELD_BUILDER_H

#include "game_field.h"

#include <cstdlib>
#include <utility>
#include <cstddef>
#include <ctime>

class GameFieldBuilder { 
private:
	GameField* game_field;
public:
	void buildSF();
	void buildField();
	void reset();
	~GameFieldBuilder();
	GameFieldBuilder(const std::pair<size_t, size_t>& field_size);
	GameField* getGameField();
};

#endif