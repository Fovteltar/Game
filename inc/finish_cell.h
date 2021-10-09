#ifndef FINISH_CELL_H
#define FINISH_CELL_H

#include "icell.h"

class FinishCell: public ICell {
	void getItem() const;
	Prototype* clone() const;
	const sf::Texture& getTexture() const;
};
#endif