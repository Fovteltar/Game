#ifndef START_CELL_H
#define START_CELL_H

#include "cell.h"

class StartCell: public Cell {
public:
	Prototype* clone() const;
	void accept(Visitor& visitor) const;
};
#endif