#include "cell.h"

Cell::~Cell() {
	delete game_object;
}

void Cell::setObject(GameObject* game_object) {
	this->game_object = game_object;
}

GameObject& Cell::getObject() {
	return *this->game_object;
}