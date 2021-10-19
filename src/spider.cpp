#include "spider.h"

Prototype* Spider::clone() const {
	return new Spider(move_manager->getCoords());
}
const sf::Texture& Spider::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("spider.png");
}

Spider::Spider(const std::pair<size_t, size_t>& coords) {
	move_manager = new CreatureMoveManager(coords);
	health = 5;
	armor = 15;
	attack = 4;
}