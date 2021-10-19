#include "finish_cell.h"

const sf::Texture& FinishCell::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("finish.png");
}

Prototype* FinishCell::clone() const {
	FinishCell* new_cell = new FinishCell();
	new_cell->setObject(dynamic_cast<GameObject*>(this->game_object->clone()));
	return new_cell;
}
