#include "player_spawner.h"

void PlayerSpawner::spawn() const {
	const std::pair<size_t, size_t>& start_coords = game_field->getStartCoords();
	Player* player = new Player(start_coords, *game_field);
	game_field->getCell(start_coords).setObject(player);
}

PlayerSpawner::PlayerSpawner(GameField& game_field) {
	this->game_field = &game_field;
}