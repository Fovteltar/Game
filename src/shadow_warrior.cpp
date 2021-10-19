#include "shadow_warrior.h"

Prototype* ShadowWarrior::clone() const {
	return new ShadowWarrior(move_manager->getCoords());
}
const sf::Texture& ShadowWarrior::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("shadow_warrior.png");
}

ShadowWarrior::ShadowWarrior(const std::pair<size_t, size_t>& coords) {
	move_manager = new CreatureMoveManager(coords);
	health = 7;
	armor = 40;
	attack = 6;
}