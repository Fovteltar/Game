#ifndef ITEM_H
#define ITEM_H

#include "game_object.h"
#include <cstddef>
#include <utility>

class Item: public GameObject {
protected:
	std::pair<size_t, size_t> coords;
public:
	const std::pair<size_t, size_t>& getCoords() const;
	virtual Prototype* clone() const = 0;
	virtual ~Item(){};
	virtual void accept(Visitor& visitor) const = 0;
};

#endif