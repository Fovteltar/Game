#ifndef START_CELL_H
#define START_CELL_H

#include "icell.h"

class StartCell: public ICell {
	void getItem() const;
	Prototype* clone() const;
	const sf::Texture& getTexture() const;
};
#endif