#ifndef RAGE_POTION_H
#define RAGE_POTION_H

#include "potion.h"

class RagePotion: public Potion {
public:
	RagePotion(const std::pair<size_t, size_t>& coords);
	Prototype* clone() const;
	const sf::Texture& getTexture() const;
};

#endif