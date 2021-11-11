#include "healing_potion.h"

HealingPotion::HealingPotion(const std::pair<size_t, size_t>& coords) {
	this->coords = coords;
	this->effect = 5;
}

void HealingPotion::use(Player& player) const {
	player.changeHealth(effect);
}

Prototype* HealingPotion::clone() const {
	return new HealingPotion(this->coords);
}

void HealingPotion::accept(Visitor& visitor) const {
	visitor.visitTextureName("healing_potion.png");
}