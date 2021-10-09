#include "common_cell.h"

void CommonCell:: getItem() const {};

Prototype* CommonCell:: clone() const {
	return new CommonCell(*this);
};

const sf::Texture& CommonCell::getTexture() const {
	Textures &t = Textures::getInstance();
	return t.getTexture("ground.png");
}