#include "spider.h"

Prototype* Spider::clone() const {
	return new Spider(move_manager->getCoords(), *game_field);
}

Spider::Spider(const std::pair<size_t, size_t>& coords, GameField& game_field) {
	move_manager = new CreatureMoveManager(coords, game_field);
	this->game_field = &game_field;
	health = 5;
	armor = 15;
	attack = 4;
}

void Spider::accept(Visitor& visitor) const {
	visitor.visitTextureName("spider.png");
}