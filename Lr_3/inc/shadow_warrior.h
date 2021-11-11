#ifndef SHADOW_WARRIOR_H
#define SHADOW_WARRIOR_H

#include "enemy.h"

class ShadowWarrior: public Enemy {
public:
	ShadowWarrior(const std::pair<size_t, size_t>& coords, GameField& game_field);
	Prototype* clone() const;
	void accept(Visitor& visitor) const;
};

#endif