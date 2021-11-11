#include "shadow_warrior.h"

Prototype* ShadowWarrior::clone() const {
	return new ShadowWarrior(move_manager->getCoords(), *game_field);
}

ShadowWarrior::ShadowWarrior(const std::pair<size_t, size_t>& coords, GameField& game_field) {
	move_manager = new CreatureMoveManager(coords, game_field);
	this->game_field = &game_field;
	health = 7;
	armor = 40;
	attack = 6;
}

void ShadowWarrior::accept(Visitor& visitor) const {
	visitor.visitTextureName("shadow_warrior.png");
}