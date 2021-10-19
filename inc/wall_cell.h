#ifndef WALL_CELL_H
#define WALL_CELL_H

#include "cell.h"

class WallCell: public Cell {
public:
	const sf::Texture& getTexture() const;
	Prototype* clone() const;
};

#endif