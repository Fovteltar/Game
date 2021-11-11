#ifndef GAME_H
#define GAME_H

#include "game_field.h"
#include "user_input.h"
#include "game_field_builder.h"
#include "renderer.h"
#include "event_manager.h"

class Game {
private:
	GameField* game_field;
	Player* player;
	bool not_ended;
	Game();
public:
	void startGame();
	static Game& getInstance();
	Game(Game &other) = delete;
	void operator=(const Game &) = delete;
	~Game();
};

#endif