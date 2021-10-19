#include "player.h"

Player::Player(const std::pair<size_t, size_t>& coords) {
	move_manager = new CreatureMoveManager(coords);
	health = 20;
	armor = 20;
	attack = 5;
}

const sf::Texture& Player::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("player.png");
}

Prototype* Player::clone() const {
	return new Player(move_manager->getCoords());
}