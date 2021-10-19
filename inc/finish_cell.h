#ifndef FINISH_CELL_H
#define FINISH_CELL_H

#include "cell.h"

class FinishCell: public Cell {
public:
	const sf::Texture& getTexture() const;
	Prototype* clone() const;
};
#endif