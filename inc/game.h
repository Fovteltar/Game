#ifndef GAME_H
#define GAME_H

#include "game_field.h"
#include "user_input.h"
#include "game_field_builder.h"
#include "renderer.h"
#include "event_manager.h"
#include "game_stats.h"

class KeyChecker;

class Game {
private:
	GameField* game_field;
	Player* player;
	GameStats* game_stats;
	bool not_ended;
	Renderer* renderer;
	EventManager* event_manager;
	Game();
public:
	void startGame();
	static Game& getInstance();
	Game(Game &other) = delete;
	void operator=(const Game &) = delete;
	~Game();
	void loadSave(GameField* new_game_field, Player* new_player, GameStats* new_game_stats);
	EventManager* getEventManager();
	GameStats* getGameStats();
	GameField* getGameField();
};

#endif