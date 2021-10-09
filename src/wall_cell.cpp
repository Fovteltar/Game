#include "wall_cell.h"

void WallCell:: getItem() const {};

Prototype* WallCell:: clone() const {
	return new WallCell(*this);
};

const sf::Texture& WallCell::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("wall.png");
}