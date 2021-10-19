#include "wall_cell.h"

const sf::Texture& WallCell::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("wall.png");
}

Prototype* WallCell::clone() const {
	WallCell* new_cell = new WallCell();
	new_cell->setObject(dynamic_cast<GameObject*>(this->game_object->clone()));
	return new_cell;
}