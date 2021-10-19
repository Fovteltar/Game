#ifndef HEALING_POTION_H
#define HEALING_POTION_H

#include "potion.h"

class HealingPotion: public Potion {
public:
	HealingPotion(const std::pair<size_t, size_t>& coords);
	Prototype* clone() const;
	const sf::Texture& getTexture() const;
};

#endif