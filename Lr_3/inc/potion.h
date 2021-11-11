#ifndef POTION_H
#define POTION_H

#include "item.h"
#include "player.h"

#include <iostream>

class Potion: public Item {
protected:
	size_t effect; // for n moves or effect power
public:
	virtual void use(Player& player) const = 0;
	const size_t& getEffect() const;
	virtual Prototype* clone() const = 0;
	virtual void accept(Visitor& visitor) const = 0;
};

#endif