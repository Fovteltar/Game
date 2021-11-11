#include "killer_ant.h"

Prototype* KillerAnt::clone() const {
	return new KillerAnt(move_manager->getCoords(), *game_field);
}

KillerAnt::KillerAnt(const std::pair<size_t, size_t>& coords, GameField& game_field) {
	move_manager = new CreatureMoveManager(coords, game_field);
	this->game_field = &game_field;
	health = 4;
	armor = 15;
	attack = 7;
}

void KillerAnt::accept(Visitor& visitor) const {
	visitor.visitTextureName("killer_ant.png");
}