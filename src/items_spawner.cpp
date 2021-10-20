#include "items_spawner.h"

void ItemsSpawner::spawn() const {
	const std::pair<size_t, size_t>& field_size = game_field->getFieldSize();
	for (size_t x = 0; x < field_size.first; x++) {
		for (size_t y = 0; y < field_size.second; y++) {
			if ((&game_field->getCell({x, y}).getObject() == nullptr) &&
			  (dynamic_cast<CommonCell*>(&game_field->getCell({x, y})) != nullptr)) {
				Item* item = nullptr;
				int chance = std::rand() % 100;
				if (chance < 5) {
					item = new HealingPotion({x, y});
				}
				else if (chance < 7) {
					item = new RagePotion({x, y});
				}
				else if (chance < 10) {
					item = new IronskinPotion({x, y});
				}
				game_field->getCell({x, y}).setObject(item);
			}
		}
	}
}

ItemsSpawner::ItemsSpawner(GameField& game_field) {
	this->game_field = &game_field;
}