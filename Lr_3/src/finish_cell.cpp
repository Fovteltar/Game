#include "finish_cell.h"

Prototype* FinishCell::clone() const {
	FinishCell* new_cell = new FinishCell();
	new_cell->setObject(dynamic_cast<GameObject*>(this->game_object->clone()));
	return new_cell;
}

void FinishCell::accept(Visitor& visitor) const {
	visitor.visitTextureName("finish_cell.png");
}