#include "creature_move_manager.h"

CreatureMoveManager::CreatureMoveManager(const std::pair<size_t, size_t>& coords, GameField& game_field):
  game_field(game_field), coords(coords) {}

void CreatureMoveManager::move(const std::pair<char, char>& difference) {
	const std::pair<size_t, size_t> old_coords = coords;
	this->coords.first += difference.first;
	this->coords.second += difference.second;
	game_field.changeObjectCoords(old_coords, coords);	
}

bool CreatureMoveManager::getIsMoved() const {
	return is_moved;
}

void CreatureMoveManager::setIsMoved(bool state) {
	is_moved = state;
}

const std::pair<size_t, size_t>& CreatureMoveManager::getCoords() const {
	return coords;
}