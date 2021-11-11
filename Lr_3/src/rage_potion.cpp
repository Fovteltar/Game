#include "rage_potion.h"

RagePotion::RagePotion(const std::pair<size_t, size_t>& coords) {
	this->coords = coords;
	this->effect = 2;
}

void RagePotion::use(Player& player) const {
	player.changeAttack(effect);
}

Prototype* RagePotion::clone() const {
	return new RagePotion(this->coords);
}

void RagePotion::accept(Visitor& visitor) const {
	visitor.visitTextureName("rage_potion.png");
}