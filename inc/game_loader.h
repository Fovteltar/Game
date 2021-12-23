#ifndef GAME_LOADER_H
#define GAME_LOADER_H

#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>

#include "game_field.h"
#include "game_stats.h"
#include "player.h"

#include "no_tag_exception.h"
#include "gf_size_exception.h"
#include "kills_rule_exception.h"
#include "steps_rule_exception.h"
#include "go_initialization_exception.h"

class Game;

class GameLoader {
private:
	GameField* new_game_field;
	GameStats* new_game_stats;
	Player* player;
public:
	GameLoader(Game* game);
};

#endif