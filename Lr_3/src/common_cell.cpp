#include "common_cell.h"

Prototype* CommonCell::clone() const {
	CommonCell* new_cell = new CommonCell();
	new_cell->setObject(dynamic_cast<GameObject*>(this->game_object->clone()));
	return new_cell;
}

void CommonCell::accept(Visitor& visitor) const {
	visitor.visitTextureName("common_cell.png");
}