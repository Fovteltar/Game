#include "player_spawner.h"
#include "game.h"

void PlayerSpawner::spawn() const {
	const std::pair<size_t, size_t>& start_coords = Game::getInstance().getGameField().getStartCoords();
	Player* player = new Player(start_coords);
	Game::getInstance().getGameField().getCell(start_coords).setObject(player);
	Game::getInstance().setPlayer(player);
}