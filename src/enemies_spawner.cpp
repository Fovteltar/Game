#include "enemies_spawner.h"
#include "game.h"

void EnemiesSpawner::spawn() const {
	GameField& game_field = Game::getInstance().getGameField();
	const std::pair<size_t, size_t>& field_size = game_field.getFieldSize();
	for (size_t x = 0; x < field_size.first; x++) {
		for (size_t y = 0; y < field_size.second; y++) {
			if ((&game_field.getCell({x, y}).getObject() == nullptr) &&
			  (dynamic_cast<CommonCell*>(&game_field.getCell({x, y})) != nullptr)) {
				Enemy* enemy = nullptr;
				int chance = std::rand() % 100;
				if (chance < 3) {
					enemy = new ShadowWarrior({x, y});
				}
				else if(chance < 6){
					enemy = new KillerAnt({x, y});
				}
				else if(chance < 9){
					enemy = new Spider({x, y});
				}
				game_field.getCell({x, y}).setObject(enemy);
			}
		}
	}
}