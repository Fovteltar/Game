#include "start_cell.h"

void StartCell:: getItem() const {};

Prototype* StartCell:: clone() const {
	return new StartCell(*this);
}

const sf::Texture& StartCell::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("start.png");
}