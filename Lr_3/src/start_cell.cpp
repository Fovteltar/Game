#include "start_cell.h"

Prototype* StartCell::clone() const {
	StartCell* new_cell = new StartCell();
	new_cell->setObject(dynamic_cast<GameObject*>(this->game_object->clone()));
	return new_cell;
}

void StartCell::accept(Visitor& visitor) const {
	visitor.visitTextureName("start_cell.png");
}