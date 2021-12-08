#include "game_stats.h"

GameStats::GameStats(): steps_amount(0), kills_amount(0) {}

const size_t& GameStats::getSteps() const {
	return steps_amount;
}

const size_t& GameStats::getKills() const {
	return kills_amount;
}

void GameStats::increaseSteps() {
	steps_amount++;
}

void GameStats::increaseKills() {
	kills_amount++;
}