#ifndef POTION_H
#define POTION_H

#include "item.h"

class Potion: public Item {
protected:
	size_t effect; // for n moves or effect power
public:
	const size_t& getEffect() const;
	virtual Prototype* clone() const = 0;
	virtual const sf::Texture& getTexture() const = 0;
};

#endif