#ifndef GAME_FIELD_DIRECTOR_H
#define GAME_FIELD_DIRECTOR_H

#include "igame_field_builder.h"

class GameFieldDirector {
private:
	IGameFieldBuilder* builder;

public:
	void setBuilder(IGameFieldBuilder* builder);
	void constructGameField();
};

#endif