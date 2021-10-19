#include "ironskin_potion.h"

IronskinPotion::IronskinPotion(const std::pair<size_t, size_t>& coords) {
	this->coords = coords;
	this->effect = 5;
}

Prototype* IronskinPotion::clone() const {
	return new IronskinPotion(this->coords);
}

const sf::Texture& IronskinPotion::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("ironskin_potion.png");
}