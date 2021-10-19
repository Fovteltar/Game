#ifndef GAME_H
#define GAME_H

#include "game_field.h"
#include "user_input.h"
#include "game_field_builder.h"
#include "player_spawner.h"
#include "enemies_spawner.h"
#include "items_spawner.h"
#include "renderer.h"
#include "event_manager.h"

class Game {
private:
	GameField* game_field;
	Player* player;
	bool not_ended = true;
	Game();
public:
	void create();
	Player& getPlayer();
	void setPlayer(Player* player);
	void setEnd();
	bool getGameState() const;
	static Game& getInstance();
	GameField& getGameField();
	Game(Game &other) = delete;
	void operator=(const Game &) = delete;
	~Game();
	void startGame();
};

#endif