#ifndef IGAME_FIELD_BUILDER_H
#define IGAME_FIELD_BUILDER_H

#include "game_field.h"

class IGameFieldBuilder {
public:
	virtual void buildSE() = 0;
	virtual void buildField() = 0;
	virtual void reset() = 0;
	virtual GameField* getGameField() = 0;
	virtual ~IGameFieldBuilder() {};
};

#endif