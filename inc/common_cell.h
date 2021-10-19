#ifndef COMMON_CELL_H
#define COMMON_CELL_H

#include "cell.h"

class CommonCell: public Cell {
public:
	const sf::Texture& getTexture() const;
	Prototype* clone() const;
};

#endif