#ifndef START_CELL_H
#define START_CELL_H

#include "cell.h"

class StartCell: public Cell {
public:
	const sf::Texture& getTexture() const;
	Prototype* clone() const;
};
#endif