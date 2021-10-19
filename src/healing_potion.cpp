#include "healing_potion.h"

HealingPotion::HealingPotion(const std::pair<size_t, size_t>& coords) {
	this->coords = coords;
	this->effect = 5;
}

Prototype* HealingPotion::clone() const {
	return new HealingPotion(this->coords);
}

const sf::Texture& HealingPotion::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("healing_potion.png");
}