#include "wall_cell.h"

Prototype* WallCell::clone() const {
	WallCell* new_cell = new WallCell();
	new_cell->setObject(dynamic_cast<GameObject*>(this->game_object->clone()));
	return new_cell;
}

void WallCell::accept(Visitor& visitor) const {
	visitor.visitTextureName("wall_cell.png");
}