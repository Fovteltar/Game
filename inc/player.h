#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

#include <iostream>

class Player: public Creature {
public:
	Player(const std::pair<size_t, size_t>& coords, GameField& game_field);
	Prototype* clone() const;
	void accept(Visitor& visitor) const;
};

#endif