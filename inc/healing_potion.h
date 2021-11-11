#ifndef HEALING_POTION_H
#define HEALING_POTION_H

#include "potion.h"
#include <string>

class HealingPotion: public Potion {
public:
	HealingPotion(const std::pair<size_t, size_t>& coords);
	void use(Player& player) const;
	Prototype* clone() const;
	void accept(Visitor& visitor) const;
};

#endif