#ifndef FINISH_CELL_H
#define FINISH_CELL_H

#include "cell.h"

class FinishCell: public Cell {
public:
	Prototype* clone() const;
	void accept(Visitor& visitor) const;
};
#endif