#ifndef COMMON_CELL_H
#define COMMON_CELL_H

#include "cell.h"

class CommonCell: public Cell {
public:
	Prototype* clone() const;
	void accept(Visitor& visitor) const;
};

#endif