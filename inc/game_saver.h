#ifndef GAME_SAVER_H
#define GAME_SAVER_H

#include <iostream>
#include <fstream>
#include <filesystem>

#include "game_field.h"
#include "creature.h"
#include "game_stats.h"

#include "game.h"

class GameSaver {
public:
	GameSaver(Game* game);
};

#endif