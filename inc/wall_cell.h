#ifndef WALL_CELL_H
#define WALL_CELL_H

#include "icell.h"

class WallCell: public ICell {
	void getItem() const;
	Prototype* clone() const;
	const sf::Texture& getTexture() const;
};

#endif