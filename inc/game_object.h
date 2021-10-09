#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "game_field.h"
#include "user_input.h"
#include "game_field_director.h"
#include "game_field_builder.h"
#include "renderer.h"

class GameObject {
private:
	GameField* game_field;
public:
	GameObject();
	~GameObject();
	void startGame();
};

#endif