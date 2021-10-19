#include "start_cell.h"

const sf::Texture& StartCell::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("start.png");
}

Prototype* StartCell::clone() const {
	StartCell* new_cell = new StartCell();
	new_cell->setObject(dynamic_cast<GameObject*>(this->game_object->clone()));
	return new_cell;
}