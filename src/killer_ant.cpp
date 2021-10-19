#include "killer_ant.h"

Prototype* KillerAnt::clone() const {
	return new KillerAnt(move_manager->getCoords());
}
const sf::Texture& KillerAnt::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("killer_ant.png");
}

KillerAnt::KillerAnt(const std::pair<size_t, size_t>& coords) {
	move_manager = new CreatureMoveManager(coords);
	health = 4;
	armor = 15;
	attack = 7;
}