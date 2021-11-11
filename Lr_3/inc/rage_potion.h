#ifndef RAGE_POTION_H
#define RAGE_POTION_H

#include "potion.h"

class RagePotion: public Potion {
public:
	RagePotion(const std::pair<size_t, size_t>& coords);
	void use(Player& player) const;
	Prototype* clone() const;
	void accept(Visitor& visitor) const;
};

#endif