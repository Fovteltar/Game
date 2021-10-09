#ifndef COMMON_CELL_H
#define COMMON_CELL_H

#include "icell.h"

class CommonCell: public ICell {
	void getItem() const;
	Prototype* clone() const;
	const sf::Texture& getTexture() const;
};

#endif