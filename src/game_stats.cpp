#include "game_stats.h"

GameStats::GameStats(): steps_amount(0), kills_amount(0) {}

const size_t& GameStats::getSteps() const {
	return steps_amount;
}

const size_t& GameStats::getKills() const {
	return kills_amount;
}

void GameStats::setSteps(const size_t& steps_amount) {
	this->steps_amount = steps_amount;
}

void GameStats::setKills(const size_t& kills_amount) {
	this->kills_amount = kills_amount;
}

void GameStats::increaseSteps() {
	steps_amount++;
}

void GameStats::increaseKills() {
	kills_amount++;
}