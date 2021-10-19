#include "rage_potion.h"

RagePotion::RagePotion(const std::pair<size_t, size_t>& coords) {
	this->coords = coords;
	this->effect = 2;
}

Prototype* RagePotion::clone() const {
	return new RagePotion(this->coords);
}

const sf::Texture& RagePotion::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("rage_potion.png");
}