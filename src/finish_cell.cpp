#include "finish_cell.h"

void FinishCell:: getItem() const {};

Prototype* FinishCell:: clone() const {
	return new FinishCell(*this);
};

const sf::Texture& FinishCell::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("finish.png");
}