#include "common_cell.h"

const sf::Texture& CommonCell::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("ground.png");
}

Prototype* CommonCell::clone() const {
	CommonCell* new_cell = new CommonCell();
	new_cell->setObject(dynamic_cast<GameObject*>(this->game_object->clone()));
	return new_cell;
}